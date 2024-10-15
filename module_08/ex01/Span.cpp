#include "./Span.hpp"

Span::Span() {
	// std::cout << "Span: Default constructor called" << std::endl;
	this->_size = 10;
}

Span::Span(unsigned int N) {
	
}

Span::~Span() {
	// std::cout << "Span: Destructor called" << std::endl;
}

Span::Span(const Span &span) {
	this->_size = span._size;
	this->_span = span._span;
	// std::cout << "Span: Copy constructor called" << std::endl;
}

Span &Span::operator=(const Span &span) {
	if (this != &span) {
		this->_size = span._size;
		this->_span = span._span;
	}
	// std::cout << "Span: Copy assignment operator called" << std::endl;
	return (*this);
}