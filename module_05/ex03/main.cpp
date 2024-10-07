/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:38 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/07 15:17:59 by albagar4         ###   ########.fr       */
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
	
	rrf = someRandomIntern.makeForm("president request", "Bender");
	if (rrf)
	{
		std::cout << rrf->getName() << std::endl;
		bury.signForm(*rrf);
		bury.executeForm(*rrf);
	}
	}
	return (0);
}
