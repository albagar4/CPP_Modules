#include "Fixed.hpp"

int	main(void){
	Fixed a(5);
	Fixed b(10);
	const Fixed c(7);
	const Fixed d(2);

	std::cout << "the biggest nbr is: " << Fixed::max(a, b) << std::endl;
	std::cout << "ths smallest nbr is: " << Fixed::min(a, b) << std::endl;
	std::cout << "the biggest nbr is: " << Fixed::max(c, d) << std::endl;
	std::cout << "ths smallest nbr is: " << Fixed::min(c, d) << std::endl;
}

//Main for the increment and decrement
// int main(void){
// 	Fixed a(5);

// 	std::cout << "a = " << a << std::endl;
// 	a++;
// 	std::cout << "a++ = " << a << std::endl;
// 	++a;
// 	std::cout << "++a = " << a << std::endl;
// 	a--;
// 	std::cout << "a-- = " << a << std::endl;
// 	--a;
// 	std::cout << "--a = " << a << std::endl;
// 	return (0);
// }

//Main for the 4 arithmetic operators
// int	main(void){
// 	Fixed a(5.5f);
// 	Fixed b(6);
// 	Fixed c (5.5f);

// 	std::cout << "| a = " << a << " && " << a.getRawBits();
// 	std::cout << "| b = " << b << " && " << b.getRawBits();
// 	std::cout << "| c = " << c << " && " << c.getRawBits() << std::endl;
// 	a = b + c;
// 	std::cout << "| a = " << a << " && " << a.getRawBits();
// 	std::cout << "| b = " << b << " && " << b.getRawBits();
// 	std::cout << "| c = " << c << " && " << c.getRawBits() << std::endl << std::endl;
// 	a = b - c;
// 	std::cout << "| a = " << a << " && " << a.getRawBits();
// 	std::cout << "| b = " << b << " && " << b.getRawBits();
// 	std::cout << "| c = " << c << " && " << c.getRawBits() << std::endl << std::endl;
// 	a = b * c;
// 	std::cout << "| a = " << a << " && " << a.getRawBits();
// 	std::cout << "| b = " << b << " && " << b.getRawBits();
// 	std::cout << "| c = " << c << " && " << c.getRawBits() << std::endl << std::endl;
// 	a = b / c;
// 	std::cout << "| a = " << a << " && " << a.getRawBits();
// 	std::cout << "| b = " << b << " && " << b.getRawBits();
// 	std::cout << "| c = " << c << " && " << c.getRawBits() << std::endl << std::endl;
// 	return (0);
// }

// Main for the 6 comparison operators
// int	main(void){
// 	Fixed a(5.5f);
// 	Fixed b(6);
// 	Fixed c (5.5f);

// 	if (a > b)
// 		std::cout << "a > b" << std::endl;
// 	if (a < b)
// 		std::cout << "a < b" << std::endl;
// 	if (a >= c)
// 		std::cout << "a >= c" << std::endl;
// 	if (a <= b)
// 		std::cout << "a <= b" << std::endl;
// 	if (a == c)
// 		std::cout << "a == c" << std::endl;
// 	if (a != b)
// 		std::cout << "a != b" << std::endl;
// }

// int main(void){
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;

// return (0);
// }
