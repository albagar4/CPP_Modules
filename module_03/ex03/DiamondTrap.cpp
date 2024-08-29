#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	std::cout << YELLOW << "DiamondTrap: Default constructor called" << RNL;
	this->name = (ClapTrap::name);
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name){
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << YELLOW << "DiamondTrap: " << this->name << " constructor called" << RNL;
}

DiamondTrap::~DiamondTrap(){
	std::cout << YELLOW << "DiamondTrap: " << this->name << " Destructor called" << RNL;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
{
	std::cout << YELLOW << "DiamondTrap: Copy constructor called" << RNL;
	this->name = diamondtrap.name;
	this->hitPoints = diamondtrap.hitPoints;
	this->energyPoints = diamondtrap.energyPoints;
	this->attackDamage = diamondtrap.attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	std::cout << YELLOW << "DiamondTrap: Copy assignment operator called" << RNL;
	this->name = diamondtrap.name;
	this->hitPoints = diamondtrap.hitPoints;
	this->energyPoints = diamondtrap.energyPoints;
	this->attackDamage = diamondtrap.attackDamage;
	return (*this);
}

void DiamondTrap::whoAmI(void){
	if (this->hitPoints > 0)
	{
		std::cout << "My name is... " << this->name << " but you remember me as " << ClapTrap::name << std::endl;
		std::cout << "rrraaAaAAhHHH... WrRAaaAahHhhHHH" << std::endl;
		std::cout << BOLD << this->name << " was so unnatural that he died in a terrible suffer" << RNL;
		this->hitPoints = 0;
	}
	else
		std::cout << "The horrible creature is already dead" << std::endl;
}
