#ifndef AFORM_HPP
# define AFORM_HPP

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

class AForm{
private:
	const	std::string name;
	bool	sign;
	const int	signGrade;
	const int	execGrade;
public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &AForm);
	AForm &operator=(const AForm &AForm);
	virtual ~AForm();
	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecGrade() const;
	// void setName(std::string newName);
	void setSign(bool sign);
	// void setSignGrade(int newSignGrade);
	// void setExecGrade(int newExecGrade);
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException: public std::exception{
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception{
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif