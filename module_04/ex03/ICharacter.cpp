/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:05:27 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/26 18:53:44 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ICharacter.hpp"

ICharacter::ICharacter(){
	std::cout << "ICharacter: Default constructor called" << std::endl;
}

ICharacter::~ICharacter(){
	std::cout << "ICharacter: Destructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &icharacter){
	(void)icharacter;
	std::cout << "ICharacter: Copy constructor called" << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &icharacter){
	(void)icharacter;
	std::cout << "ICharacter: Copy assignment operator called" << std::endl;
	return (*this);
}