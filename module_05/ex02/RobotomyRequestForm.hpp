#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyrequestform);
	~RobotomyRequestForm();
	std::string getTarget(void) const;
	void execute(Bureaucrat const & executor) const;
	class FormNotSigned: public std::exception{
		const char *what() const throw();
	};
};

#endif