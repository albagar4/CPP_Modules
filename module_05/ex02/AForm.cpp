#include "./AForm.hpp"

AForm::AForm(): name("Default AForm"), sign(false), signGrade(80), execGrade(120){
	// std::cout << "AForm: Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade): name(name), sign(false), signGrade(150), execGrade(120){
	// std::cout << "AForm: " << name << " constructor called" << std::endl;
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

AForm::~AForm(){
	// std::cout << "AForm: Destructor called" << std::endl;
}

AForm::AForm(const AForm &aForm): name(aForm.name), sign(aForm.sign), signGrade(aForm.signGrade), execGrade(aForm.execGrade){
	// std::cout << "AForm: Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &aForm){
	// std::cout << "AForm: Copy assignment operator called" << std::endl;
	this->sign = aForm.sign;
	const_cast<std::string&>(this->name) = aForm.name;
	const_cast<int&>(this->signGrade) = aForm.signGrade;
	const_cast<int&>(this->execGrade) = aForm.execGrade;
	return (*this);
}

std::string AForm::getName() const{
	return (this->name);
}

bool AForm::getSign() const{
	return (this->sign);
}

int AForm::getSignGrade() const{
	return (this->signGrade);
}

int AForm::getExecGrade() const{
	return (this->execGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat){
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

const char *AForm::GradeTooHighException::what() const throw(){
	return ("The grade you're trying to assign is too high");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("The grade you're trying to assign is too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj){
	os << BOLD << obj.getName() << " AForm Info:" << std::endl;
	os << "- Sign Status: " << RESET << obj.getSign() << std::endl;
	os << BOLD << "- Sign Grade: " << RESET << obj.getSignGrade() << std::endl;
	os << BOLD << "- Exec Grade: " << RESET << obj.getExecGrade();
	return (os);
}
