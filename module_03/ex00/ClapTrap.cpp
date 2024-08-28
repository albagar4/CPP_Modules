#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << CYAN << "ClapTrap: Default constructor called" << RNL;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << CYAN << "ClapTrap: " << name << " constructor called" << RNL;
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::~ClapTrap(){
	std::cout << CYAN << "ClapTrap: " << name << " Destructor called" << RNL;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap){
	std::cout << CYAN << "ClapTrap: Copy constructor called" << RNL;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap){
	std::cout << CYAN << "ClapTrap: Copy assignment operator called" << RNL;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (this->energyPoints > 0)
	{
		std::cout << this->name << " has attacked " << target << "!!" << std::endl;
		std::cout << target << " has received " << this->attackDamage << " points of damage" << std::endl; 
		this->energyPoints--;
	}
	else
		std::cout << this->name << " has no Energy points left" << std::endl;
}
