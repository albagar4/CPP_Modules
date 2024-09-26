#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource, public AMateria{
  public:
	MateriaSource();
	MateriaSource(const MateriaSource &materiasource);
	MateriaSource(const AMateria &materiacopy);
	MateriaSource &operator=(const MateriaSource &materiasource);
	~MateriaSource();
	void learnMateria(AMateria *materia);
	int recursiveFunction(std::string const &type, int i);
	AMateria* createMateria(std::string const &type);
	MateriaSource* clone() const;
};

#endif