/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:48:48 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/24 17:27:07 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat(){
	std::cout << BRED << "Cat: Default constructor called: " << RESET;
	this->type = "Cat";
	this->sound = "Meow";
	this->catBrain = new Brain();
}

Cat::Cat(std::string type){
	std::cout << BRED << "Cat: " << type << " constructor called: " << RESET;
	this->type = type;
	this->sound = "Meow";
	this->catBrain = new Brain();
}

Cat::~Cat(){
	std::cout << BRED << "Cat: Destructor called: " << RESET;
	delete this->catBrain;
}

Cat::Cat(const Cat &cat){
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->type = cat.type;
	this->sound = cat.sound;
	this->catBrain = cat.catBrain;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "Cat: Copy assignment operator called" << std::endl;
	this->type = cat.type;
	this->sound = cat.sound;
	this->catBrain = cat.catBrain;
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << BOLD << this->getType() << ": " << RESET << this->sound << std::endl;
}
