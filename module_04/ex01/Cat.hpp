#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
protected:
	std::string sound;
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);
	~Cat();
	void makeSound(void) const;
};

#endif