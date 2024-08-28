#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << BRED << "ScavTrap: Default constructor called" << RNL;
}

ScavTrap::ScavTrap(std::string name){
	std::cout << BRED << "ScavTrap: " << name << " constructor called" << RNL;
	this->name = name;
}

ScavTrap::~ScavTrap(){
	std::cout << BRED << "ScavTrap: " << this->name << " Destructor called" << RNL;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap){
	std::cout << BRED << "ScavTrap: Copy constructor called" << RNL;
	this->name = scavtrap.name;
	this->hitPoints = scavtrap.hitPoints;
	this->energyPoints = scavtrap.energyPoints;
	this->attackDamage = scavtrap.attackDamage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
	std::cout << BRED << "ScavTrap: Copy assignment operator called" << RNL;
	this->name = scavtrap.name;
	this->hitPoints = scavtrap.hitPoints;
	this->energyPoints = scavtrap.energyPoints;
	this->attackDamage = scavtrap.attackDamage;
	return (*this);
}

void ScavTrap::guardGate(){
	std::cout << this->name << " has his guard up" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->energyPoints > 0 && this->hitPoints > 0)
		std::cout << "OH NO!! " << this->name << " has attacked " << target << " with a wet sock!" << std::endl;
	else if (this->hitPoints < 0)
		std::cout << this->name << " is dead... he cannot attack..." << std::endl;
	else
		std::cout << this->name << " doesn't have Energy Points anymore" << std::endl;
	this->energyPoints--;
}
