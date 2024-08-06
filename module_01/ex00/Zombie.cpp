#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "Constructor called for: " << this->name << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Destructor called for: " << this->name << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
