/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:51:55 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/25 12:51:58 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cure.hpp"

Cure::Cure(){
	std::string type = "cure";
	this->type = &type;
	std::cout << GREEN "Cure: Default constructor called" RNL;
}

Cure::~Cure(){
	std::cout << GREEN "Cure: Destructor called" RNL;
}

Cure::Cure(const Cure &cure){
	this->type = cure.type;
	std::cout << GREEN "Cure: Copy constructor called" RNL;
}

Cure &Cure::operator=(const Cure &cure){
	this->type = cure.type;
	std::cout << GREEN "Cure: Copy assignment operator called" RNL;
	return (*this);
}

AMateria* Cure::clone() const{
	std::cout << GREEN "It appears you've clone a " << RESET;
	AMateria *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter &target){
	std::cout << GREEN "Cure: \"* heals " << target.getName() << "'s wounds *\"" RNL;
}
