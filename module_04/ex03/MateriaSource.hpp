#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

class MateriaSource
{
  public:
	MateriaSource();
	MateriaSource(const MateriaSource &materiasource);
	MateriaSource &operator=(const MateriaSource &materiasource);
	~MateriaSource();

  private:
	
};

#endif