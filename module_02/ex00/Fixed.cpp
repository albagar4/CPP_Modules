#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed &cpy){
	this->value = cpy.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &right_value){
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = right_value.value;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
