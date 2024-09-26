/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:26:34 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/26 17:08:25 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::AMateria(std::string const &type): AMateria{
	std::cout << CYAN "AMateria: " << this->getType() << " constructor called" << RNL;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
	{
		if (this->materies[i] != NULL)
			delete this->materies[i];
	}
	std::cout << "MateriaSource: Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource){
	for (int i = 0; i < 4; i++)
	{
		if (materiasource.materies[i] != NULL)
			this->materies[i] = materiasource.materies[i];
	}
	std::cout << "MateriaSource: Copy constructor called" << std::endl;
}

MateriaSource::MateriaSource(const AMateria &materiacopy): AMateria(materiacopy){
	std::cout << "MateriaSource: AMateria Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiasource){
	for (int i = 0; i < 4; i++)
	{
		if (materiasource.materies[i] != NULL)
			this->materies[i] = materiasource.materies[i];
	}
	std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia){
	for (int i = 0; i < 4; i++)
	{
		if (this->materies[i] == NULL && materia)
		{
			this->materies[i] = new MateriaSource(*materia);
			break ;
		}
	}
}

AMateria* MateriaSource::clone() const{
	std::cout << "You can't clone anything" << std::endl;
	this->
}
