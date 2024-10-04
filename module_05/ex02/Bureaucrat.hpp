#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
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

class AForm;

class Bureaucrat{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incrementGrade(unsigned int nbr);
	void decrementGrade(unsigned int nbr);
	void signForm(AForm &aform);
	class GradeTooHighException: public std::exception{
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception{
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
