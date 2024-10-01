/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:09:57 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/01 15:36:34 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog(){
	std::cout << PURPLE << "Dog: Default constructor called: " << RESET;
	this->type = "Dog";
	this->sound = "Wof Wof";
	this->dogBrain = new Brain();
}

Dog::Dog(std::string type){
	std::cout << PURPLE << "Dog: " << type << " constructor called: " << RESET;
	this->type = type;
	this->sound = "Wof Wof";
	this->dogBrain = new Brain();
}

Dog::~Dog(){
	std::cout << PURPLE << "Dog: Destructor called: " << RESET;
	delete this->dogBrain;
}

Dog::Dog(const Dog &Dog){
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->type = Dog.type;
	this->sound = Dog.sound;
	this->dogBrain = Dog.dogBrain->clone();
}

Dog &Dog::operator=(const Dog &Dog)
{
	std::cout << "Dog: Copy assignment operator called" << std::endl;
	this->type = Dog.type;
	this->sound = Dog.sound;
	this->dogBrain = Dog.dogBrain->clone();
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << BOLD << this->getType() << ": " << RESET << this->sound << std::endl;
}