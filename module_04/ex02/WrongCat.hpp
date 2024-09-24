#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat: public Animal{
protected:
	std::string sound;
	Brain		*wcatBrain;
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &Wrongcat);
	WrongCat &operator=(const WrongCat &Wrongcat);
	~WrongCat();
	// void makeSound(void) const;
};

#endif