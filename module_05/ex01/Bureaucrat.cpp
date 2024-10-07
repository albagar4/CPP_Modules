/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:30 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/07 15:04:49 by albagar4         ###   ########.fr       */
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

void Bureaucrat::incrementGrade(void){
	try{
		if (this->grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->grade--;
		std::cout << "Grade after: " << this->grade << std::endl;
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

void Bureaucrat::decrementGrade(void){
	try{
		if (this->grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->grade++;
	}
	catch (std::exception &e){
		std::cout << BRED << e.what() << RNL;
	}
}

void Bureaucrat::signForm(Form &form){
	if (form.getSign() == false)
	{
		form.beSigned(*this);
		if (form.getSign() == true)
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		else
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because of the previous reason" << std::endl;
	}
	else
		std::cout << form.getName() << " is already signed" << std::endl;
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