#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>

class IMateriaSource
{
  public:
	IMateriaSource();
	IMateriaSource(const IMateriaSource &imateriasource);
	IMateriaSource &operator=(const IMateriaSource &imateriasource);
	~IMateriaSource();

  private:
	
};

#endif