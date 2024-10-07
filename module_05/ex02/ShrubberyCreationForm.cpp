#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 147, 137){
	// std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
	this->setSign(false);
	this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 147, 137){
	// std::cout << "ShrubberyCreationForm: Parameterized constructor called" << std::endl;
	this->setSign(false);
	this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	// std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform): AForm(shrubberycreationform.getName(), shrubberycreationform.getSignGrade(), shrubberycreationform.getExecGrade()){
	// std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	this->setSign(shrubberycreationform.getSign());
	this->target = shrubberycreationform.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberycreationform){
	if (this != &shrubberycreationform)
	{
		AForm::operator=(shrubberycreationform);
		this->target = shrubberycreationform.target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	try{
		if (this->getSign() == true && executor.getGrade() <= this->getExecGrade())
		{
			std::ofstream formFile((this->target + "_shrubbery").c_str());
			if (!formFile)
			{
				std::cout << "Error on creating file" << std::endl;
				return ;
			}
			if (formFile.is_open()) {
				formFile << "        *" << std::endl;
				formFile << "       ***" << std::endl;
				formFile << "      *****" << std::endl;
				formFile << "     *******" << std::endl;
				formFile << "    *********" << std::endl;
				formFile << "   ***********" << std::endl;
				formFile << "  *************" << std::endl;
				formFile << " ***************" << std::endl;
				formFile << "*****************" << std::endl;
				formFile << "       |||" << std::endl;
				formFile << "       |||" << std::endl;

				formFile.close();
			} 
			else 
				std::cout << "The file couldn't be opened" << std::endl;
		}
		else if (this->getSign() == false)
			throw FormNotSigned();
		else
			throw GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

const char *ShrubberyCreationForm::FormNotSigned::what() const throw(){
	return ("The form you're trying to execute is not signed");
}
