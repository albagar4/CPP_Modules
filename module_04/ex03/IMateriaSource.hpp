#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource{
protected:
	AMateria *materies[4];
public:
	IMateriaSource();
	IMateriaSource(const IMateriaSource &imateriasource);
	IMateriaSource &operator=(const IMateriaSource &imateriasource);
	virtual ~IMateriaSource();
	virtual void learnMateria(AMateria *materia) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif