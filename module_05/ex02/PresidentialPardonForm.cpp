#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("President", 25, 5){
	// std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
	this->setSign(false);
	this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("President", 25, 5){
	// std::cout << "PresidentialPardonForm: Parameterized constructor called" << std::endl;
	this->setSign(false);
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	// std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform): AForm(presidentialpardonform.getName(), presidentialpardonform.getSignGrade(), presidentialpardonform.getExecGrade()){
	// std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	this->setSign(presidentialpardonform.getSign());
	this->target = presidentialpardonform.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialpardonform){
	// std::cout << "PresidentialPardonForm: Copy assignment operator called" << std::endl;
	if (this != &presidentialpardonform)
	{
		AForm::operator=(presidentialpardonform);
		this->target = presidentialpardonform.target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try{
		if (this->getSign() == true && executor.getGrade() <= this->getExecGrade())
			std::cout << BOLD << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << RNL;
		else if (this->getSign() == false)
			throw FormNotSigned();
		else
			throw GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

const char *PresidentialPardonForm::FormNotSigned::what() const throw(){
	return ("The form you're trying to execute is not signed");
}
