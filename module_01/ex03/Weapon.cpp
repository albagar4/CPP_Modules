#include "Weapon.hpp"

Weapon::Weapon(){

}

Weapon::Weapon(std::string type){
	this->type = type;
	std::cout << "Weapon " << this->getType() << " has been created" << std::endl;
}

Weapon::~Weapon(){
	std::cout << "Weapon has been erased" << std::endl;
}

const std::string&	Weapon::getType(){
	const std::string	&typeRef = this->type;
	return (typeRef);
}

void    Weapon::setType(std::string newType){
	this->type = newType;
	return ;
}
