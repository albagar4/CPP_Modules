/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:34:52 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/25 12:25:54 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AMateria.hpp"

AMateria::AMateria(){
	std::cout << CYAN "AMateria: Default constructor called" RNL;
}

AMateria::AMateria(std::string const &type){
	this->type = &type;
	std::cout << CYAN "AMateria: " << this->getType() << " constructor called" << RNL;
}

AMateria::~AMateria(){
	std::cout << CYAN "AMateria: Destructor called" RNL;
}

AMateria::AMateria(const AMateria &amateria){
	this->type = amateria.type;
	std::cout << CYAN "AMateria: Copy constructor called" << RNL;
}

AMateria &AMateria::operator=(const AMateria &amateria){
	this->type = amateria.type;
	std::cout << CYAN "AMateria: Copy assignment operator called" RNL;
	return (*this);
}

std::string const &AMateria::getType() const{
	return (*this->type);
}

void AMateria::use(ICharacter &target){
	(void)target;
	std::cout << "You shouldn't be seeing this message" << std::endl;
}
