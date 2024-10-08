#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter{
protected:
	int size;
	AMateria *slots[4];
	AMateria **bin;
public:
	Character();
	Character(std::string const name);
	Character(const Character &character);
	Character &operator=(const Character &character);
	~Character();
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	void TrashCan(AMateria *trash);
};

#endif