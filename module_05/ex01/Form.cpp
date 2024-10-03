#include "./Form.hpp"

Form::Form(): name("Default Form"), sign(false), signGrade(80), execGrade(120){
	// std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade): name(name), sign(false), signGrade(150), execGrade(120){
	// std::cout << "Form: " << name << " constructor called" << std::endl;
	try{
		if (signGrade < 1)
			throw GradeTooHighException();
		else if (signGrade > 150)
			throw GradeTooLowException();
		else
			const_cast<int&>(this->signGrade) = signGrade;
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

Form::~Form(){
	// std::cout << "Form: Destructor called" << std::endl;
}

Form::Form(const Form &form): name(form.name), sign(form.sign), signGrade(form.signGrade), execGrade(form.execGrade){
	// std::cout << "Form: Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &form){
	// std::cout << "Form: Copy assignment operator called" << std::endl;
	this->sign = form.sign;
	const_cast<std::string&>(this->name) = form.name;
	const_cast<int&>(this->signGrade) = form.signGrade;
	const_cast<int&>(this->execGrade) = form.execGrade;
	return (*this);
}

std::string Form::getName() const{
	return (this->name);
}

bool Form::getSign() const{
	return (this->sign);
}

int Form::getSignGrade() const{
	return (this->signGrade);
}

int Form::getExecGrade() const{
	return (this->execGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat){
	try{
		if (bureaucrat.getGrade() <= this->signGrade)
			this->sign = true;
		else
			throw GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

const char *Form::GradeTooHighException::what() const throw(){
	return ("The grade you're trying to assign is too high");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("The grade you're trying to assign is too low");
}

std::ostream& operator<<(std::ostream& os, const Form& obj){
	os << BOLD << obj.getName() << " Form Info:" << std::endl;
	os << "- Sign Status: " << RESET << obj.getSign() << std::endl;
	os << BOLD << "- Sign Grade: " << RESET << obj.getSignGrade() << std::endl;
	os << BOLD << "- Exec Grade: " << RESET << obj.getExecGrade();
	return (os);
}
