/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:38 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/07 14:32:04 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){
	{
	Intern someRandomIntern;
	AForm* rrf;
	Bureaucrat bury("Steve", 1);
	
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << rrf->getName() << std::endl;
	bury.signForm(*rrf);
	bury.executeForm(*rrf);
	}
	return (0);
}
