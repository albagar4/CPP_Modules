/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:09:57 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 16:10:04 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog(){
	std::cout << PURPLE << "Dog: Default constructor called" << RNL;
	this->type = "Dog";
	this->sound = "Wof Wof";
}

Dog::Dog(std::string type){
	std::cout << PURPLE << "Dog: " << type << " constructor called" << RNL;
	this->type = type;
	this->sound = "Wof Wof";
}

Dog::~Dog(){
	std::cout << PURPLE << "Dog: Destructor called" << RNL;
}

Dog::Dog(const Dog &Dog){
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->type = Dog.type;
	this->sound = Dog.sound;
}

Dog &Dog::operator=(const Dog &Dog)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	this->type = Dog.type;
	this->sound = Dog.sound;
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << BOLD << this->getType() << ": " << RESET << this->sound << std::endl;
}