#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45){
	// std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
	this->setSign(false);
	this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45){
	// std::cout << "RobotomyRequestForm: Parameterized constructor called" << std::endl;
	this->setSign(false);
	this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	// std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform): AForm(robotomyrequestform.getName(), robotomyrequestform.getSignGrade(), robotomyrequestform.getExecGrade()){
	// std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	this->setSign(robotomyrequestform.getSign());
	this->target = robotomyrequestform.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyrequestform){
	// std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
	if (this != &robotomyrequestform)
	{
		AForm::operator=(robotomyrequestform);
		this->target = robotomyrequestform.target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		if (this->getSign() == true && executor.getGrade() <= this->getExecGrade())
		{
			if (time(NULL) % 2) {
				std::cout << this->getTarget() << " has been robotized" << std::endl;
			} 
			else {
				std::cout <<this->getTarget() << " couldn't be robotomized" << std::endl;
			}
		}
		else if (this->getSign() == false)
			throw FormNotSigned();
		else
			throw GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

const char *RobotomyRequestForm::FormNotSigned::what() const throw(){
	return ("The form you're trying to execute is not signed");
}
