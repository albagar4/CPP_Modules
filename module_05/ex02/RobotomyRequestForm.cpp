#include "./RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45){
	// std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
	this->setSign(false);
	this->target = "Default";
	this->robotomized = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45){
	// std::cout << "RobotomyRequestForm: Parameterized constructor called" << std::endl;
	this->setSign(false);
	this->target = target;
	this->robotomized = false;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	// std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform): AForm(robotomyrequestform.getName(), robotomyrequestform.getSignGrade(), robotomyrequestform.getExecGrade()){
	// std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	this->setSign(robotomyrequestform.getSign());
	this->target = robotomyrequestform.target;
	this->robotomized = robotomyrequestform.robotomized;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyrequestform){
	// std::cout << "RobotomyRequestForm: Copy assignment operator called" << std::endl;
	if (this != &robotomyrequestform)
	{
		AForm::operator=(robotomyrequestform);
		this->target = robotomyrequestform.target;
		this->robotomized = robotomyrequestform.robotomized;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const{
	return (this->target);
}

bool RobotomyRequestForm::getRobotomized(void) const{
	return (this->robotomized);
}

void RobotomyRequestForm::setRobotomized(bool robotomized){
	this->robotomized = robotomized;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		if (this->getSign() == true && executor.getGrade() <= this->getExecGrade())
		{
			if (this->getRobotomized() == true)
			{
				std::cout << this->getTarget() << " has been robotized" << std::endl;
				this->setRobotomized(false);
			}
			else
			{
				std::cout <<this->getTarget() << " couldn't be robotomized" << std::endl;
				this->setRobotomized(true);
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
