#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include "ICharacter.hpp"

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

class ICharacter;

class AMateria{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &amateria);
	AMateria &operator=(const AMateria &amateria);
	virtual ~AMateria();
	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif