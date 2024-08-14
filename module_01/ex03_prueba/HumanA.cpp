#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	this->WeaponA = &weapon;
	this->name = name;
	std::cout << this->name << " was born and took his weapon " << CYAN << this->WeaponA->getType() << RNL;
}

HumanA::~HumanA(){
	std::cout << this->name << " has died" << std::endl;
}

void	HumanA::attack(){
	std::cout << this->name << " attacked with his " << CYAN << this->WeaponA->getType() << RNL;
}
