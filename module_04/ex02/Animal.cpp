/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:48:41 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/24 18:09:34 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

Animal::Animal(){
	std::cout << CYAN << "Animal: Default constructor called" << RNL;
	this->type = "Unknown";
}

Animal::~Animal(){
	std::cout << CYAN << "Animal: " << this->getType() << " Destructor called" << RNL;
}

Animal::Animal(const Animal &animal){
	std::cout << CYAN << "Animal: Copy constructor called" << RNL;
	this->type = animal.type;
}

Animal &Animal::operator=(const Animal &animal){
	std::cout << CYAN << "Animal: Copy assignment operator called" << RNL;
	this->type = animal.type;
	return (*this);
}

std::string Animal::getType(void) const{
	return (this->type);
}

void Animal::setType(std::string newType){
	this->type = newType;
}
