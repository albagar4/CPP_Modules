#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal){
	this->type = wronganimal.type;
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal){
	this->type = wronganimal.type;
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
	return (*this);
}

std::string WrongAnimal::getType(void) const{
	return (this->type);
}

void WrongAnimal::setType(std::string newType){
	this->type = newType;
	return ;
}

void WrongAnimal::makeSound(void) const{
	std::cout << BOLD "*** Painful noises ***" << RNL;
}
