#include <iostream>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
			std::cout << (char)toupper(argv[i][j]);
		if (i != argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
