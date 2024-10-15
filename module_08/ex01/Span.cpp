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

int Span::shortestSpan(void) {
	if (this->_span.empty() || this->_span.size() == 1)
		throw InvalidSize();

	int min_snap = INT32_MAX;
	for (long unsigned int i = 0; i < this->_span.size(); i++)
	{
		for (long unsigned int j = 0; j < this->_span.size(); j++)
		{
			if (j == i)
				j++;
			if ((this->_span[i] - this->_span[j]) >= 0 && (this->_span[i] - this->_span[j]) < min_snap)
				min_snap = this->_span[i] - this->_span[j];
		}
	}
	std::cout << "The shortest Span is: ";
	return (min_snap);
}

int Span::longestSpan(void) {
	if (this->_span.empty() || this->_span.size() == 1)
		throw InvalidSize();

	int min_value = INT32_MAX;
	int max_value = INT32_MIN;
	for (long unsigned int i = 0; i < this->_span.size(); i++)
	{
		if (this->_span[i] < min_value)
			min_value = this->_span[i];
		if (this->_span[i] > max_value)
			max_value = this->_span[i];
	}
	std::cout << "The longest Span is: ";
	return (max_value - min_value);
}

const char *Span::FullSpanError::what() const throw() {
	return ("The Span you're trying to fill is full");
}

const char *Span::InvalidSize::what() const throw() {
	return ("There is an issue with the size of the Span");
}

void Span::fillSpan(int *nbr_list, int size) {
	if (this->_span.size() + size > this->_size)
		throw InvalidSize();
	for (int i = 0; i < size; i++)
		addNumber(nbr_list[i]);
}
