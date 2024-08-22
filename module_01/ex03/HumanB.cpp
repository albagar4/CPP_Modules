#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	this->WeaponB = NULL;
	std::cout << this->name << " was born" << std::endl;
}

HumanB::~HumanB(){
	std::cout << this->name << " has died" << std::endl;
}

void	HumanB::attack(){
	if (this->WeaponB != NULL)
		std::cout << this->name << " attacks with his " << BRED << this->WeaponB->getType() << RNL;
	else
		std::cout << this->name << " attacks with his bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	this->WeaponB = &newWeapon;
}
