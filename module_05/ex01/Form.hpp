#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdbool.h>
#include "Bureaucrat.hpp"

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

class Bureaucrat;

class Form{
private:
	const	std::string name;
	bool	sign;
	const int	signGrade;
	const int	execGrade;
public:
	Form();
	Form(std::string name, int signGrade);
	Form(const Form &form);
	Form &operator=(const Form &form);
	~Form();
	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
	class GradeTooHighException: public std::exception{
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception{
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif