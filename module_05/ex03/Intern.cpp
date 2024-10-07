#include "./Intern.hpp"

Intern::Intern(){
	// std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::~Intern(){
	// std::cout << "Intern: Destructor called" << std::endl;
}

Intern::Intern(const Intern &intern){
	(void)intern;
	// std::cout << "Intern: Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &intern){
	(void)intern;
	// std::cout << "Intern: Copy assignment operator called" << std::endl;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target){
	AForm *arrayList[3] = {
		new ShrubberyCreationForm(target), 
		new RobotomyRequestForm(target), 
		new PresidentialPardonForm(target)
	};
	std::string	arrayStr[3] = {"shrubbery creation", "robotomy request", "president request"};
	
	for (int i = 0; i < 3; i++)
	{
		if (arrayStr[i] == formName)
		{
			AForm *form = arrayList[i];
			std::cout << "Intern creates " << form->getName() << std::endl;
			for (int j = i + 1; j < 3; j++)
				delete arrayList[j];
			return (form);
		}
		delete arrayList[i];
	}
	std::cout << "The form you're trying to create doesn't exist" << std::endl;
	std::cout << "Usage of the Intern: makeform(<formName>, <target>)" << std::endl << "<formName> options: <shrubbery creation> <robotomy request> <president request>" << std::endl;
	return (NULL);
}
