/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:13:42 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 14:14:02 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
	ClapTrap wizard("Merlin the Wizard");
	ClapTrap gnome("David the Gnome");

	wizard.attack("Goblin Frodo");
	wizard.takeDamage(2);
	wizard.beRepaired(1);
	gnome.takeDamage(15);
	gnome.beRepaired(5);
	return (0);
}
