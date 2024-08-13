#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->WeaponB = NULL;
	std::cout << this->name << " was born" << std::endl;
}

HumanB::~HumanB(){
	std::cout << this->name << " has died" << std::endl;
}

void	HumanB::attack(){
	std::cout << this->name << " has attacked with his " << this->WeaponB->getType();
}

void	HumanB::setWeapon(Weapon &newWeapon){
	this->WeaponB = newWeapon;
}
