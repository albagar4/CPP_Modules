#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Basic constructor called" << std::endl;
}

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Constructor called for: " << RED << this->name << RNL;
}

Zombie::~Zombie(){
	std::cout << "Destructor called for: " << RED << this->name << RNL;
}

void	Zombie::announce(void){
	std::cout << RED << this->name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name){
	this->name = name;
	return ;
}
