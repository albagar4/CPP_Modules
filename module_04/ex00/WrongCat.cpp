/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:11:45 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 16:27:27 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << PURPLE << "WrongCat: Default constructor called" << RNL;
	this->type = "WrongCat";
	this->sound = "Grrr";
}

WrongCat::WrongCat(std::string type){
	std::cout << PURPLE << "WrongCat: " << type << " constructor called" << RNL;
	this->type = type;
	this->sound = "Grrr";
}

WrongCat::~WrongCat(){
	std::cout << PURPLE << "WrongCat: Destructor called" << RNL;
}

WrongCat::WrongCat(const WrongCat &WrongCat){
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	this->type = WrongCat.type;
	this->sound = WrongCat.sound;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	this->type = WrongCat.type;
	this->sound = WrongCat.sound;
	return (*this);
}

void WrongCat::makeSound(void) const{
	std::cout << BOLD << this->getType() << ": " << RESET << this->sound << std::endl;
}