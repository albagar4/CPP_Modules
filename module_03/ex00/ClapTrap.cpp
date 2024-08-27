#include "./ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	// std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	// std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	// std::cout << "ClapTrap: Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
	// std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
	return (*this);
}