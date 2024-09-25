/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:20:48 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/25 11:20:57 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << CYAN << "AAnimal: Default constructor called" << RNL;
	this->type = "Unknown";
}

AAnimal::~AAnimal(){
	std::cout << CYAN << "AAnimal: " << this->getType() << " Destructor called" << RNL;
}

AAnimal::AAnimal(const AAnimal &AAnimal){
	std::cout << CYAN << "AAnimal: Copy constructor called" << RNL;
	this->type = AAnimal.type;
}

AAnimal &AAnimal::operator=(const AAnimal &AAnimal){
	std::cout << CYAN << "AAnimal: Copy assignment operator called" << RNL;
	this->type = AAnimal.type;
	return (*this);
}

std::string AAnimal::getType(void) const{
	return (this->type);
}

void AAnimal::setType(std::string newType){
	this->type = newType;
}
