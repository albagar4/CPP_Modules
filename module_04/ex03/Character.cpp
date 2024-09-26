/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:05:33 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/26 18:26:32 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"

Character::Character(){
	size = 0;
	std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(std::string const name){
	size = 0;
	this->name = &name;
	std::cout << "Character: " << this->getName() << " constructor called" << std::endl;
}

Character::~Character(){
	for (int i = 0; i < size; i++)
	{
		if (i < 4 && this->slots[i] != NULL)
			delete this->slots[i];
		delete this->bin[i];
	}
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

std::string const &Character::getName() const{
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
	if (this->slots[idx] != NULL && (idx >= 0 && idx <= 3))
	{
		this->TrashCan(this->slots[idx]);
		for (int i = idx; i < 4; i++)
			this->slots[i] = this->slots[i + 1];
		this->slots[3] = NULL;
	}
	else
		std::cout << "You can't unequip something that doesn't exist" << std::endl;
}

void Character::TrashCan(AMateria *trash){
	this->size++;
	this->bin = new AMateria*[size];
	this->bin[size - 1] = trash;
}

void Character::use(int idx, ICharacter &target){
	if (this->slots[idx] != NULL && (idx >= 0 && idx <= 3))
		this->slots[idx]->use(target);
	else
		std::cout << "You can't use something that doesn't exist" << std::endl;
}
