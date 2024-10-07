#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include "AForm.hpp"

#define RED    "\033[0;31m"
#define BRED    "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET    "\033[0m"
#define RNL    "\033[0m\n"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY "\033[1;30m"
#define PURPLE "\033[35m"
#define LGRAY "\033[0;37m"
#define BOLD "\033[1;37m"

class ShrubberyCreationForm: public AForm{
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberycreationform);
	~ShrubberyCreationForm();
	std::string getTarget(void) const;
	void execute(Bureaucrat const & executor) const;
	class FormNotSigned: public std::exception{
		const char *what() const throw();
	};
};


#endif