/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:25:44 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/27 16:48:02 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./IMateriaSource.hpp"

IMateriaSource::IMateriaSource(){
	// std::cout << "IMateriaSource: Default constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource(){
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (this->materies[i] != NULL)
	// 		delete this->materies[i];
	// }
	// std::cout << "IMateriaSource: Destructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &imateriasource){
	for (int i = 0; i < 4; i++)
	{
		if (imateriasource.materies[i] != NULL)
			this->materies[i] = imateriasource.materies[i];
	}
	// std::cout << "IMateriaSource: Copy constructor called" << std::endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &imateriasource){
	for (int i = 0; i < 4; i++)
	{
		if (imateriasource.materies[i] != NULL)
			this->materies[i] = imateriasource.materies[i];
	}
	// std::cout << "IMateriaSource: Copy assignment operator called" << std::endl;
	return (*this);
}