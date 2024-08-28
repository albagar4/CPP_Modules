#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << PURPLE << "FragTrap: Default constructor called" << RNL;
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name){
	std::cout << PURPLE << "FragTrap: " << name << " constructor called" << RNL;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::~FragTrap(){
	std::cout << PURPLE << "FragTrap: " << this->name << " Destructor called" << RNL;
}

FragTrap::FragTrap(const FragTrap &fragtrap){
	std::cout << PURPLE << "FragTrap: Copy constructor called" << RNL;
	this->name = fragtrap.name;
	this->hitPoints = fragtrap.hitPoints;
	this->energyPoints = fragtrap.energyPoints;
	this->attackDamage = fragtrap.attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
	std::cout << PURPLE << "FragTrap: Copy assignment operator called" << RNL;
	this->name = fragtrap.name;
	this->hitPoints = fragtrap.hitPoints;
	this->energyPoints = fragtrap.energyPoints;
	this->attackDamage = fragtrap.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuy(void){
	if (this->hitPoints > 0)
	{
		std::cout << this->name << " highfives his team and he feels better :D" << std::endl;
		std::cout << BOLD << "**" << this->name << " recovers 10 hit points**" << RNL;
		this->hitPoints += 10;
	}
	else
		std::cout << this->name << " is dead, it's not appropiate highfive a cadaver" << std::endl;
}
