/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:11:45 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/24 18:17:42 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << PURPLE << "WrongCat: Default constructor called: " << RESET;
	this->type = "WrongCat";
	this->sound = "Grrr";
	this->wcatBrain = new Brain();
}

WrongCat::WrongCat(std::string type){
	std::cout << PURPLE << "WrongCat: " << type << " constructor called: " << RESET;
	this->type = type;
	this->sound = "Grrr";
	this->wcatBrain = new Brain();
}

WrongCat::~WrongCat(){
	std::cout << PURPLE << "WrongCat: Destructor called: " << RESET;
	delete this->wcatBrain;
}

WrongCat::WrongCat(const WrongCat &WrongCat){
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	this->type = WrongCat.type;
	this->sound = WrongCat.sound;
	this->wcatBrain = WrongCat.wcatBrain;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;
	this->type = WrongCat.type;
	this->sound = WrongCat.sound;
	this->wcatBrain = WrongCat.wcatBrain;
	return (*this);
}

// void WrongCat::makeSound(void) const{
// 	std::cout << BOLD << this->getType() << ": " << RESET << this->sound << std::endl;
// }