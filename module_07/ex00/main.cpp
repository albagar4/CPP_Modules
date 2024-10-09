#include "whatever.hpp"

int main(void) {
	int a = -2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::minValue( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::maxValue( a, b ) << std::endl << std::endl;

	std::string c = "allergy";
	std::string d = "bottle of water";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::minValue( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::maxValue( c, d ) << std::endl << std::endl;

	float e = 2.5f;
	float f = 5.7f;

	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::minValue( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::maxValue( e, f ) << std::endl;

	return (0);
}
