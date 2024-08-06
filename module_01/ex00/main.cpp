#include "Zombie.hpp"

// - zombie's constructor and destructor are automatically called
// - newZombie comes from a function that returns a pointer to the Zombie Class
// and uses new and delete to allocate and unallocate it correctly
// - randomChump is a function that creates, announces and destroys the Zombie all by itself

int	main(void){
	Zombie	zombie("Arthur");
	Zombie	*_newZombie = newZombie("Tadeo");

	randomChump("Thomas");
	zombie.announce();
	_newZombie->announce();
	delete _newZombie;
	return (0);
}
