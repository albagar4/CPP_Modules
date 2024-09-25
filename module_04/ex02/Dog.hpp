#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog: public AAnimal{
protected:
	std::string sound;
	Brain		*dogBrain;
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &Dog);
	Dog &operator=(const Dog &Dog);
	~Dog();
	void makeSound(void) const;
};

#endif