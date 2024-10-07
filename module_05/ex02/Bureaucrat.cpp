/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:30 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/07 12:19:37 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"){
	this->grade = 150;
	// std::cout << "Bureaucrat: Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){
	// std::cout << "Bureaucrat: " << name << " Constructor called" << std::endl;
	try{
		if (grade < 1)
		{
			this->grade = 150;
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			this->grade = 150;
			throw GradeTooLowException();
		}
		else
			this->grade = grade;
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): name(bureaucrat.name){
	this->grade = bureaucrat.grade;
	// std::cout << "Bureaucrat: Copy Constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat){
	const_cast<std::string&>(this->name) = bureaucrat.name;
	this->grade = bureaucrat.grade;
	// std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	// std::cout << "Bureaucrat: Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const{
	return (this->name);
}

int Bureaucrat::getGrade() const{
	return (this->grade);
}

void Bureaucrat::incrementGrade(unsigned int nbr){
	try{
		std::cout << "Grade before: " << this->grade << std::endl;
		if (this->grade - (int)nbr < 1)
			throw GradeTooHighException();
		else
			this->grade -= nbr;
		std::cout << "Grade after: " << this->grade << std::endl;
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

void Bureaucrat::decrementGrade(unsigned int nbr){
	try{
		if (this->grade + nbr > 150)
			throw GradeTooLowException();
		else
			this->grade += nbr;
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

void Bureaucrat::signForm(AForm &aForm){
	if (aForm.getSign() == false)
	{
		aForm.beSigned(*this);
		if (aForm.getSign() == true)
			std::cout << this->getName() << " signed " << aForm.getName() << std::endl;
		else
			std::cout << this->getName() << " couldn't sign " << aForm.getName() << " because of the previous reason" << std::endl;
	}
	else
		std::cout << aForm.getName() << " is already signed" << std::endl;
}

void Bureaucrat::executeForm(AForm &aForm){
	aForm.execute(*this);
	if (aForm.getSign() == true && this->getGrade() <= aForm.getExecGrade())
		std::cout << this->getName() << " executed " << aForm.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't execute " << aForm.getName() << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ("The grade you're trying to assign is too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ("The grade you're trying to assign is too high");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << BOLD << obj.getName() << " bureaucrat grade " << obj.getGrade() << RESET;
	return (os);
}