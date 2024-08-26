#include "Fixed.hpp"

Fixed::Fixed(){
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int nbr){
	// std::cout << "Int nbr constructor called" << std::endl;
	this->value = nbr << this->bits;
}

Fixed::Fixed(const float nbr){
	// std::cout << "Float nbr constructor called" << std::endl;
	this->value = roundf(nbr * (1 << this->bits));
}

Fixed::Fixed(const Fixed &cpy){
	this->value = cpy.getRawBits();
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& right_value){
	// std::cout << "Copy assignment operator called" << std::endl;
	this->value = right_value.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& right_value){
	if (this->toFloat() > right_value.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& right_value){
	if (this->toFloat() < right_value.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& right_value){
	if (this->toFloat() >= right_value.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& right_value){
	if (this->toFloat() <= right_value.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& right_value){
	if (this->toFloat() == right_value.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& right_value){
	if (this->toFloat() != right_value.toFloat())
		return (true);
	return (false);
}

float Fixed::operator+(const Fixed& right_value){
	float addition;

	addition = this->toFloat() + right_value.toFloat();
	return (addition);
}

float Fixed::operator-(const Fixed& right_value){
	float substraction;

	substraction = this->toFloat() - right_value.toFloat();
	return (substraction);
}

float Fixed::operator*(const Fixed& right_value){
	float multiplication;

	multiplication = this->toFloat() * right_value.toFloat();
	return (multiplication);
}

float Fixed::operator/(const Fixed& right_value){
	float division;

	division = this->toFloat() / right_value.toFloat();
	return (division);
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw){
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat(void) const{
	return (static_cast<float>(this->value) / (1 << this->bits));
}

int Fixed::toInt(void) const{
	return (this->value >> this->bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
	os << obj.toFloat();
	return (os);
}
