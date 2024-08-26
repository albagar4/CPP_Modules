#include "Fixed.hpp"

int	main(void){
	Fixed a(5);
	Fixed b(3.75f);

	std::cout << BRED << "a from rawBits: " << a.getRawBits() << RNL;
	std::cout << BRED << "b from rawBits: " << b.getRawBits() << RNL;

	std::cout << CYAN << "a from toInt: " << a.toInt() << RNL;
	std::cout << CYAN << "b from toInt: " << b.toInt() << RNL;
	std::cout << CYAN << "b from toFloat: " << b.toFloat() << RNL;
}

// int main( void ) {

// Fixed a;
// Fixed const b(10);
// Fixed const c(42.42f);
// Fixed const d(b);

// a = Fixed(1234.4321f);

// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;

// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

// return (0);
// }
