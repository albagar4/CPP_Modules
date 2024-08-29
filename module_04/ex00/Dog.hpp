#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
protected:
	std::string sound;
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &Dog);
	Dog &operator=(const Dog &Dog);
	~Dog();
	void makeSound(void) const;
};

#endif