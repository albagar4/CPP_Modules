#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern{
public:
	Intern();
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);
	~Intern();
	AForm *makeForm(std::string formName, std::string target);
};

#endif