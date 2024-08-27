#include "Fixed.hpp"
#include "Point.hpp"

void errorVertex(void){
	const Point a(0, 0);
	const Point b(4, 0);
	const Point c (2, 3);
	const Point point (0, 0);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;
}

void errorEdge(void){
	const Point a(0, 0);
	const Point b(4, 0);
	const Point c (2, 3);
	const Point point (2, 0);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;
}

void example4(void){
	const Point a(-1, -1);
	const Point b(2, -1);
	const Point c (0, 2);
	const Point point (-2, 2);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;
}

void example3(void){
	const Point a(-2, 0);
	const Point b(2, 0);
	const Point c (0, 3);
	const Point point (0, 1);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;
}

void example2(void){
	const Point a(0, 0);
	const Point b(3, 0);
	const Point c (1, 2);
	const Point point (3, 3);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;
}

void example1(void){
	const Point a(1, 1);
	const Point b(5, 1);
	const Point c (3, 4);
	const Point point (3, 2);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;;
}

int main(void){
	const Point a(0, 0);
	const Point b(4, 0);
	const Point c (2, 3);
	const Point point (2, 1);

	std::cout << "a = " << a << " | b = " << b << " | c = " << c << " && point = " << point << std::endl;
	if (bsp(a, b, c, point))
		std::cout << GREEN << "bsp is: " << bsp(a, b, c, point) << RNL;
	else
		std::cout << BRED << "bsp is: " << bsp(a, b, c, point) << RNL;
	example1();
	example2();
	example3();
	example4();
	errorEdge();
	errorVertex();
	return (0);
}
