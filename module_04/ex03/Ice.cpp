/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:52:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/27 16:35:36 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Ice.hpp"

Ice::Ice(){
	std::string type = "ice";
	this->type = type;
	// std::cout << GRAY "Ice: Default constructor called" RNL;
}

Ice::~Ice(){
	// std::cout << GRAY "Ice: Destructor called" RNL;
}

Ice::Ice(const Ice &ice): AMateria(ice) {
	// std::cout << GRAY "Ice: Copy constructor called" RNL;
}

Ice &Ice::operator=(const Ice &ice){
	this->type = ice.type;
	// std::cout << GRAY "Ice: Copy assignment operator called" RNL;
	return (*this);
}

AMateria* Ice::clone() const{
	std::cout << GRAY "It appears you've clone a " << RESET;
	AMateria *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter &target){
	std::cout << GRAY "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" RNL;
}
