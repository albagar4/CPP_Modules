#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialpardonform);
	~PresidentialPardonForm();
	std::string getTarget(void) const;
	void execute(Bureaucrat const & executor) const;
	class FormNotSigned: public std::exception{
		const char *what() const throw();
	};
};

#endif