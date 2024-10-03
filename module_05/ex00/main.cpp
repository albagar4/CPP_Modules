/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:38 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/03 12:48:50 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat error("Fulgencio", 200);
	Bureaucrat test("Bruno", 1);

	std::cout << error << std::endl;
	std::cout << test << std::endl;
	test.decrementGrade(30);
	std::cout << test << std::endl;
	test.decrementGrade(150);
	std::cout << test << std::endl;
	test.incrementGrade(120);
	std::cout << test << std::endl;
	return (0);
}
