#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Incorrect nbr of parameters" << std::endl;
		std::cout << "Usage: ./btc <filename>" << std::endl;
	}
	else {
		std::ifstream firstFile(argv[1]);
		if (!firstFile.is_open()) {
			std::cout << "File not found" << std::endl;
			return (0);
		}
		std::string file;
		std::getline(firstFile,file, '\0');
		
		BitcoinExchange test(file);
		test.pairCreation();
		firstFile.close();
	}
	return (0);
}
