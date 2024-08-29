/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:02:30 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 17:03:15 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain(){
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain(const Brain &brain){
	std::cout << "Brain: Copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain){
	std::cout << "Brain: Copy assignment operator called" << std::endl;
	return (*this);
}