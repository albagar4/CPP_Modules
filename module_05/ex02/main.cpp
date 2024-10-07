/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:38 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/07 12:34:31 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	Bureaucrat lowGrade("lowy", 145);
	Bureaucrat mediumGrade("midi", 70);
	Bureaucrat highGrade("biggy", 3);
	ShrubberyCreationForm shrub("forest");
	RobotomyRequestForm robby("human");
	PresidentialPardonForm pres("normal citizen");

	// {
	// 	lowGrade.signForm(shrub);
	// 	lowGrade.signForm(robby);
	// 	lowGrade.signForm(pres);
	// 	lowGrade.executeForm(shrub);
	// 	lowGrade.executeForm(robby);
	// 	lowGrade.executeForm(pres);
	// }
	// {
	// 	mediumGrade.signForm(shrub);
	// 	mediumGrade.signForm(robby);
	// 	mediumGrade.signForm(pres);
	// 	mediumGrade.executeForm(shrub);
	// 	mediumGrade.executeForm(robby);
	// 	mediumGrade.executeForm(pres);
	// }
	{
		highGrade.signForm(shrub);
		highGrade.signForm(robby);
		highGrade.signForm(pres);
		highGrade.executeForm(shrub);
		highGrade.executeForm(robby);
		highGrade.executeForm(robby);
		highGrade.executeForm(robby);
		highGrade.executeForm(pres);
	}
	
	return (0);
}
