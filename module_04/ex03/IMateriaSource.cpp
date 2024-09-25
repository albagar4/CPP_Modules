#include "./IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	// std::cout << "IMateriaSource: Default constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource()
{
	// std::cout << "IMateriaSource: Destructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &imateriasource)
{
	// std::cout << "IMateriaSource: Copy constructor called" << std::endl;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &imateriasource)
{
	// std::cout << "IMateriaSource: Copy assignment operator called" << std::endl;
	return (*this);
}