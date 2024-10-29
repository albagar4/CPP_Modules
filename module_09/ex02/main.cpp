#include "PmergeMe.hpp"

bool ft_isdigit(char *str) {
	for (unsigned long int i = 0; i < strlen(str); i++) {
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

int main(int argc, char **argv) {
	if (argc < 3) {
		std::cout << "Wrong nbr of parameters" << std::endl;
		std::cout << "Usage: ./PmergeMe <nbr01> <nbr02> [...] <nbrXX>" << std::endl;
	}
	else {
		int nbr_array[argc -1];

		for (int i = 1; i < argc; i++) {
			if (!ft_isdigit(argv[i])) {
				std::cerr << "Not valid value found" << argv[i] << std::endl;
				return (-1);
			}
			else
				nbr_array[i - 1] = atoi(argv[i]);
		}

		PmergeMe test(nbr_array, (argc - 1));

		test.setVector();
		test.setDeque();
	}
	return (0);
}
