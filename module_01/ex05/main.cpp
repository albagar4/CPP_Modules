#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Wrong nbr of parameters" << std::endl;
	else
	{
		if (!std::string(argv[1]).compare("DEBUG")
			|| !std::string(argv[1]).compare("INFO")
			|| !std::string(argv[1]).compare("WARNING")
			|| !std::string(argv[1]).compare("ERROR"))
		{
			Harl	littleHarl;
			littleHarl.complain(argv[1]);
		}
		else
			std::cout << "Please introduce one of the following complains: [DEBUG] [INFO] [WARNING] [ERROR]" << std::endl;
	}
	return (0);
}