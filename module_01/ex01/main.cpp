#include "Zombie.hpp"

int	main(void){
	int		N = 20;
	Zombie	*_zombieHorde;

	_zombieHorde = zombieHorde(N, "Amanda");
	for (int i = 0; i < N; i++){
		std::cout << LGRAY << "Zombie[" << i << "]: " << RESET;
		_zombieHorde[i].announce();
	}
	delete [] _zombieHorde;
	return (0);
}
