#include "./Span.hpp"

Span::Span() {
	// std::cout << "Span: Default constructor called" << std::endl;
	this->_size = 10;
}

Span::Span(unsigned int N) {
	// std::cout << "Span: Parameterized constructor called" << std::endl;
	this->_size = N;
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

void Span::addNumber(int nbr) {
	if (this->_span.size() == this->_size)
		throw FullSpanError();
	this->_span.push_back(nbr);
}

void Span::shortestSpan(void) {
	if (this->_span.empty() || this->_span.size() == 1)
		throw InvalidSize();

	int min_snap = INT32_MAX;
	for (int i = 0; i < this->_span.size(); i++)
	{
		
	}
}
