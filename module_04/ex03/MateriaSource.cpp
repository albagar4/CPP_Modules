#include "./MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "MateriaSource: Default constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "MateriaSource: Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiasource)
{
	// std::cout << "MateriaSource: Copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiasource)
{
	// std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
	return (*this);
}