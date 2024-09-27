/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:26:34 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/27 17:02:08 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"

MateriaSource::MateriaSource(){
	// std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
	{
		if (this->materies[i] != NULL)
			delete this->materies[i];
	}
	// std::cout << "MateriaSource: Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource): IMateriaSource(materiasource){
	// std::cout << "MateriaSource: Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiasource){
	for (int i = 0; i < 4; i++)
	{
		if (materiasource.materies[i] != NULL)
			this->materies[i] = materiasource.materies[i];
	}
	// std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia){
	for (int i = 0; i < 4; i++)
	{
		if (this->materies[i] == NULL && materia)
		{
			AMateria *copy = NULL;
			copy = materia;
			this->materies[i] = copy;
			return ;
		}
	}
}

int MateriaSource::recursiveFunction(std::string const &type, int i){
	for (int j = (i + 1); j < 4; j++)
	{
		if (this->materies[j] && type.compare(this->materies[j]->getType()) == 0)
		{
			i = j;
			this->recursiveFunction(type, i);
		}
	}
	return (i);
}

AMateria* MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++)
	{
		if (this->materies[i] != NULL && type.compare(this->materies[i]->getType()) == 0)
		{
			i = this->recursiveFunction(type, i);
			AMateria *copy = NULL;
			copy = this->materies[i];
			return (copy);
		}
	}
	return (0);
}
