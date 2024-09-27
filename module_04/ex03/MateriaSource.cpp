/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:26:34 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/27 18:20:48 by albagar4         ###   ########.fr       */
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
			std::cout << "Your MateriaSource has learned " << materia->getType() << std::endl;
			AMateria *copy = NULL;
			copy = materia;
			this->materies[i] = copy;
			return ;
		}
	}
	delete materia;
	std::cout << "Your MateriaSource doesn't have space left for learning" << std::endl;
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
			std::cout << "Your MateriaSource has created " << type << std::endl;
			i = this->recursiveFunction(type, i);
			AMateria *copy = NULL;
			copy = this->materies[i];
			return (copy);
		}
	}
	std::cout << "Your MateriaSource can't create " << type << std::endl;
	return (0);
}
