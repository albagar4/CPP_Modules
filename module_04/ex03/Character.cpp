/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:05:33 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/25 16:07:35 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"

Character::Character(){
	size = 0;
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::~Character(){
	std::cout << "Character: Destructor called" << std::endl;
}

Character::Character(const Character &character){
	this->size = character.size;
	this->name = character.name;
	for (int i = 0; i < 4; i++)
		this->slots[i] = character.slots[i];
	std::cout << "Character: Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &character){
	this->size = character.size;
	this->name = character.name;
	for (int i = 0; i < 4; i++)
		this->slots[i] = character.slots[i];
	std::cout << "Character: Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const &Character::getName(){
	return (*this->name);
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == NULL)
			this->slots[i] = m;
	}
}

void Character::unequip(int idx){
	if (this->slots[idx] != NULL)
	{
		
		this->bin = &(this->slots[idx]);
	}
}

void Character::TrashCan(AMateria *trash){
	
}
