/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:35:38 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/03 15:57:19 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat test01("David", 70);
	Bureaucrat test02("Thomas", 130);
	Form form01("Taxes", 100);
	Form form02("LowError", 151);
	Form formm03("HighError", 0);

	std::cout << form01 << std::endl;
	test02.signForm(form01);
	std::cout << form01 << std::endl;
	test01.signForm(form01);
	std::cout << form01 << std::endl;
	test01.signForm(form01);
	std::cout << form01 << std::endl;
	return (0);
}
