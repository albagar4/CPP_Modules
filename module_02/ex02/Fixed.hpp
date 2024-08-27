#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdbool.h>
#include <cmath>

#define RED    "\033[0;31m"
#define BRED    "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET    "\033[0m"
#define RNL    "\033[0m\n"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY "\033[1;30m"
#define PURPLE "\033[35m"
#define LGRAY "\033[0;37m"
#define BOLD "\033[1;37m"

class Fixed{
private:
	int	value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed(const Fixed &cpy);
	Fixed& operator=(const Fixed& right_value);
	bool operator>(const Fixed& right_value);
	bool operator<(const Fixed& right_value);
	bool operator>=(const Fixed& right_value);
	bool operator<=(const Fixed& right_value);
	bool operator==(const Fixed& right_value);
	bool operator!=(const Fixed& right_value);
	float operator+(const Fixed& right_value);
	float operator-(const Fixed& right_value);
	float operator*(const Fixed& right_value);
	float operator/(const Fixed& right_value);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	~Fixed();
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed& min(Fixed& first, Fixed& second);
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static Fixed& max(Fixed& first, Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif