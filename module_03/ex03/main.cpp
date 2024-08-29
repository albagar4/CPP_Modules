/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:15:29 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 14:15:32 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	DiamondTrap hardcode;
	DiamondTrap mutant("Xero");

	hardcode.printStats();
	std::cout << std::endl;
	mutant.printStats();
	std::cout << std::endl;

	hardcode.attack("cow Lola");
	hardcode.beRepaired(5);
	hardcode.whoAmI();
	hardcode.beRepaired(5);
	std::cout << std::endl;
	mutant.attack("human Finn");
	mutant.beRepaired(10);
	mutant.whoAmI();
	mutant.beRepaired(10);
	return (0);
}
