#include "Weapon.hpp"

Weapon::Weapon(){
	std::cout << "Weapon was created!" << std::endl;
}

Weapon::Weapon(std::string name){
	this->type = name;
	std::cout << "Weapon " << GREEN << this->type << RESET << " was created" << std::endl;
}

Weapon::~Weapon(){
	std::cout << "Weapon was destroyed" << std::endl;
}

const std::string&	Weapon::getType(){
	return (this->type);
}

void	Weapon::setType(std::string newType){
	this->type = newType;
}
