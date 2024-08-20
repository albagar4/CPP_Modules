#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Wrong nbr of parameters" << std::endl;
	else
	{
		Harl	littleHarl;
		littleHarl.complain(argv[1]);
	}
	return (0);
}