#ifndef AAnimal_HPP
# define AAnimal_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "Brain.hpp"

#define RED    "\033[0;31m"
#define BRED    "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET    "\033[0m"
#define RNL    "\033[0m\n"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY "\033[1;30m"
#define PURPLE "\033[35m"
#define LGRAY "\033[0;37m"
#define BOLD "\033[1;37m"

class AAnimal{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal &AAnimal);
	AAnimal &operator=(const AAnimal &AAnimal);
	virtual ~AAnimal();
	std::string getType(void) const;
	void setType(std::string newType);
	virtual void makeSound(void) const = 0;
};

#endif