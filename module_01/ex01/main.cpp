#include "Zombie.hpp"

int	main(void){
	int		N = 7;
	Zombie	*_zombieHorde;

	_zombieHorde = zombieHorde(N, "Amanda");
	for (int i = 0; i < N; i++){
		std::cout << BRED << "Zombie[" << i << "]: " << RESET;
		_zombieHorde[i].announce();
	}
	delete [] _zombieHorde;
	return (0);
}
