#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	// std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string file) {
	// std::cout << "BitcoinExchange: Parameterized constructor called" << std::endl;
	// if (file.empty())
	// 	throw EmptyFile();
	this->file = file;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange) {
	// std::cout << "BitcoinExchange: Copy constructor called" << std::endl;
	if (!bitcoinexchange.map.empty())
		this->map = bitcoinexchange.map;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinexchange) {
	// std::cout << "BitcoinExchange: Copy assignment operator called" << std::endl;
	if (!bitcoinexchange.map.empty())
		this->map = bitcoinexchange.map;
	return (*this);
}

void BitcoinExchange::pairCreation(void) {
	size_t start = 0;
	size_t end = 0;
	std::string line;

	while (end != std::string::npos) {
		end = this->file.find('\n', start);
		if (end != std::string::npos) {
			line = this->file.substr(start, end - start);
			start = end + 1;
		}
		else
			line = this->file.substr(start);
		std::cout << line << std::endl;
	}
}
