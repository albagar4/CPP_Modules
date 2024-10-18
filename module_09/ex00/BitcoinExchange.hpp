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
	BitcoinExchange(std::string csv, std::string input);
	BitcoinExchange(const BitcoinExchange &bitcoinexchange);
	BitcoinExchange &operator=(const BitcoinExchange &bitcoinexchange);
	~BitcoinExchange();

	void lineDivision(void);
	void pairCreation(std::string line);
	class InvalidFile: public std::exception {
		const char *what() const throw();
	};

	void determineValue(void);
	bool checkInput(std::string line);
private:
	BitcoinExchange();
	std::map<std::string, float> map;
	std::string csv;
	std::string input;
	std::string date;
	std::string value;
};

bool isLeapYear(int year);
bool validateDate(std::string date);

#endif