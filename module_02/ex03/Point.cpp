#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)) {
	std::cout << "Basic constructor Point called" << std::endl;
}

Point::Point(const float x, const float y): x(Fixed(x)), y(Fixed(y)) {
	std::cout << "Parameterized constructor Point called" << std::endl;
}

Point::Point(const Point& cpy): x(Fixed(cpy.x)), y(Fixed(cpy.y)) {
	std::cout << "Cpy constructor called" << std::endl;
}

Point& Point::operator=(const Point& right_value){
	if (this != &right_value)
	{
		const_cast<Fixed&>(this->x) = right_value.getX();
		const_cast<Fixed&>(this->y) = right_value.getY();
	}
	return (*this);
}

Fixed Point::getX(void) const{
	return (this->x);
}

Fixed Point::getY(void) const{
	return (this->y);
}

Point::~Point(){
	std::cout << "Destructor Point called" << std::endl;
}
