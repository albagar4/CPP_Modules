#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	// std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string csv, std::string input) {
	// std::cout << "BitcoinExchange: Parameterized constructor called" << std::endl;
	// if (csv.empty())
	// 	throw Emptycsv();
	this->csv = csv;
	this->input = input;
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

void BitcoinExchange::lineDivision(void) {
	size_t start = 0;
	size_t end = 0;
	std::string line;

	while (end != std::string::npos) {
		end = this->csv.find('\n', start);
		if (end != std::string::npos) {
			line = this->csv.substr(start, end - start);
			start = end + 1;
		}
		else
			line = this->csv.substr(start);
		this->pairCreation(line);
	}
}

void BitcoinExchange::pairCreation(std::string line) {
	std::string first;
	std::string second;

	if (!line.empty()) {
		first = line.substr(0, (line.find(",")));
		second = line.substr(line.find(",") + 1);
		for (long unsigned int i = 0; i < second.size(); i++) {
			if (!isdigit(second[i]) && second[i] != '.')
				throw InvalidFile();
		}
		this->map.insert(std::make_pair(first, atof(second.c_str())));
	}
}

const char *BitcoinExchange::InvalidFile::what() const throw() {
	return ("The values on the csv aren't correct");
}

void BitcoinExchange::determineValue(void) {
	size_t start = 0;
	size_t end = 0;
	std::string line;

	while (end != std::string::npos) {
		end = this->input.find('\n', start);
		if (end != std::string::npos) {
			line = this->input.substr(start, end - start);
			start = end + 1;
		}
		else
			line = this->input.substr(start);
		if (this->checkInput(line)) {
			std::map<std::string, float>::iterator it = this->map.find(this->date);
			if (it != this->map.end())
				this->result = it->second * atof(this->value.c_str());
			else
				this->result = this->closestDate();
			std::cout << this->date << " => " << this->value << " = " << this->result << std::endl;
		}
	}
}

bool BitcoinExchange::checkInput(std::string line) {
	if (line.empty()) {
		std::cout << "Can't check an empty line" << std::endl;
		return (false);
	}

	this->date = line.substr(0, line.find("|") - 1);
	this->value = line.substr(line.find("|") + 2);

	if (!validateDate(this->date))
		return (false);

	for (long unsigned int i = 0; i < this->value.size(); i++) {
		if (!isdigit(this->value[i]) && this->value[i] != '.') {
			if (this->value[0] == '-')
				std::cout << "Error: not a positive number" << std::endl;
			else
				std::cout << "Error: value is not a number" << std::endl;
			return (false);
		}
	}

	if (atof(this->value.c_str()) > INT32_MAX) {
		std::cout << "Error: the value is too high" << std::endl;
		return (false);
	}

	return (true);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool validateDate(std::string date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cout << "Error: bad input => " << date << std::endl;
        return (false);
	}

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
	int dayspermonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month == 2 && isLeapYear(year))
        dayspermonth[1] = 29;

    if (month < 1 || month > 12 || day < 1 || day > dayspermonth[month - 1]) {
		std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }
    return (true);
}

int BitcoinExchange::daysDifference(std::string date1, std::string date2) {
	int year1 = std::atoi(date1.substr(0, 4).c_str());
	int month1 = std::atoi(date1.substr(5, 2).c_str());
	int day1 = std::atoi(date1.substr(8, 2).c_str());

	int year2 = std::atoi(date2.substr(0, 4).c_str());
	int month2 = std::atoi(date2.substr(5, 2).c_str());
	int day2 = std::atoi(date2.substr(8, 2).c_str());

	int totalDays1 = year1 * 365 + month1 * 30 + day1;
	int totalDays2 = year2 * 365 + month2 * 30 + day2;

	if (totalDays1 - totalDays2 <= 0)
		return (INT32_MAX);
	else
		return (totalDays1 - totalDays2);
}

float BitcoinExchange::closestDate(void) {
	std::map<std::string, float>::const_iterator it = this->map.begin();
    std::string closestDate = it->first;
    int compare = daysDifference(this->date, it->first);

	while (it != this->map.end()) {
		int difference = daysDifference(this->date, it->first);
		if (difference < compare) {
			compare = difference;
			closestDate = it->first;
		}
		++it;
	}
	it = this->map.find(closestDate);
	return (it->second * atof(this->value.c_str()));
}
