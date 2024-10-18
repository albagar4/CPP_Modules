#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange(std::string file);
	BitcoinExchange(const BitcoinExchange &bitcoinexchange);
	BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
	~BitcoinExchange();
	void pairCreation(void);
private:
	BitcoinExchange();
	std::map<std::string, float> map;
	std::string file;
};

#endif