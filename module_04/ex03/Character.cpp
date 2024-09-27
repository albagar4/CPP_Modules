/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:05:33 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/27 17:06:36 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"

Character::Character(){
	size = 0;
	// std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(std::string const name){
	size = 0;
	this->name = &name;
	// std::cout << "Character: " << this->getName() << " constructor called" << std::endl;
}

Character::~Character(){
	for (int i = 0; i < size; i++)
	{
		if (i < 4 && this->slots[i] != NULL)
			delete this->slots[i];
		if (this->bin[i] != NULL)
			delete this->bin[i];
	}
	// delete this->bin[size];
	// std::cout << "Character: Destructor called" << std::endl;
}

Character::Character(const Character &character): ICharacter(character) {
	for (int i = 0; i < 4; i++)
		this->slots[i] = character.slots[i];
	// std::cout << "Character: Copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &character){
	this->size = character.size;
	this->name = character.name;
	for (int i = 0; i < 4; i++)
		this->slots[i] = character.slots[i];
	// std::cout << "Character: Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const &Character::getName() const{
	return (*this->name);
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++)
	{
		if (this->slots[i] == NULL)
		{
			std::cout << this->getName() << " equips " << m->getType() << std::endl;
			this->slots[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx){
	if (this->slots[idx] != NULL && (idx >= 0 && idx <= 3))
	{
		std::cout << this->getName() << " unequips " << this->slots[idx]->getType() << std::endl;
		this->TrashCan(this->slots[idx]);
		for (int i = idx; i < 4; i++)
			this->slots[i] = this->slots[i + 1];
		this->slots[3] = NULL;
	}
	else
		std::cout << "You can't unequip something that doesn't exist" << std::endl;
}

void Character::TrashCan(AMateria *trash){
	// this->bin[size] = new AMateria*;
	this->size++;
	memset((void *)this->bin[size - 1], 0, sizeof(AMateria));
	this->bin[size - 1] = trash;
}

void Character::use(int idx, ICharacter &target){
	if (this->slots[idx] != NULL && (idx >= 0 && idx <= 3))
		this->slots[idx]->use(target);
	else
		std::cout << "You can't use something that doesn't exist" << std::endl;
}
