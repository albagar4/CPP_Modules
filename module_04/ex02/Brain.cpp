/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:02:30 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/01 15:35:44 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain(){
	std::cout << YELLOW << "Brain: Default constructor called" << RNL;
}

Brain::~Brain(){
	std::cout << YELLOW << "Brain: Destructor called" << RNL;
}

Brain::Brain(const Brain &brain){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << YELLOW << "Brain: Copy constructor called" << RNL;
}

Brain &Brain::operator=(const Brain &brain){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << YELLOW << "Brain: Copy assignment operator called" << RNL;
	return (*this);
}

Brain *Brain::clone(void){
	Brain *clone = new Brain(*this);
	return (clone);
}
