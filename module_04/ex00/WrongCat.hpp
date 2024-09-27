#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
protected:
	std::string sound;
public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &Wrongcat);
	WrongCat &operator=(const WrongCat &Wrongcat);
	~WrongCat();
	void makeSound(void) const;
};

#endif