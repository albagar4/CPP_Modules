/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:14:23 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 14:14:26 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ClapTrap wizard("Merlin the Wizard");
	ScavTrap gnome("David the Gnome");

	wizard.printStats();
	std::cout << std::endl;
	gnome.printStats();
	std::cout << std::endl;
	wizard.attack("Goblin Frodo");
	wizard.takeDamage(2);
	wizard.beRepaired(1);
	std::cout << std::endl;
	gnome.attack("sister Minnie");
	gnome.guardGate();
	gnome.takeDamage(7);
	gnome.beRepaired(5);
	return (0);
}
