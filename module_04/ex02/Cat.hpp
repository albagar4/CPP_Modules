#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat: public AAnimal{
protected:
	std::string sound;
	Brain		*catBrain;
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);
	~Cat();
	void makeSound(void) const;
};

#endif