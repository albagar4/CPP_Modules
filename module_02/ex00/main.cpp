#include "Fixed.hpp"

int	main(void){
	Fixed a;
	Fixed b(a);
	Fixed c;

	std::cout << BRED << "A: " << a.getRawBits() << RNL;
	std::cout << CYAN << "B: " << b.getRawBits() << RNL;
	a.setRawBits(2);
	std::cout << BRED << "A: " << a.getRawBits() << RNL;
	std::cout << CYAN << "B: " << b.getRawBits() << RNL;

	c = b;
	std::cout << GREEN << "C: " << c.getRawBits() << RNL;
	std::cout << CYAN << "B: " << b.getRawBits() << RNL;
	b.setRawBits(5);
	std::cout << GREEN << "C: " << c.getRawBits() << RNL;
	std::cout << CYAN << "B: " << b.getRawBits() << RNL;
	c.setRawBits(3);
	std::cout << GREEN << "C: " << c.getRawBits() << RNL;
	std::cout << CYAN << "B: " << b.getRawBits() << RNL;
}

// int main(void){
// Fixed a;
// Fixed b(a);
// Fixed c;

// c = b; // c.operator=(b)

// std::cout << a.getRawBits() << std::endl;
// std::cout << b.getRawBits() << std::endl;
// std::cout << c.getRawBits() << std::endl;

// return (0);
// }
