#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {
	this->name = name;
	this->WeaponA = weapon;
	std::cout << this->name << " was born and took his weapon " << this->WeaponA.getType() << std::endl;
}

HumanA::~HumanA(){
	std::cout << this->name << " has died" << std::endl;
}

void	HumanA::attack(){
	std::cout << this->name << " attacked with his " << this->WeaponA.getType() << std::endl;
}
