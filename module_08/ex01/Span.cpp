#include "./Span.hpp"

Span::Span() {
	// std::cout << "Span: Default constructor called" << std::endl;
	this->_size = 10;
	this->_span.reserve(this->_size);
}

Span::Span(unsigned int N) {
	// std::cout << "Span: Parameterized constructor called" << std::endl;
	this->_size = N;
	this->_span.reserve(this->_size);
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

	int min_span = INT32_MAX;
	std::vector<int> sorted = this->_span;
	std::sort(sorted.begin(), sorted.end());
	for (long unsigned int i = 1; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < min_span)
			min_span = sorted[i] - sorted[i - 1];
	}
	std::cout << "The shortest Span is: ";
	return (min_span);
}

int Span::longestSpan(void) {
	if (this->_span.empty() || this->_span.size() == 1)
		throw InvalidSize();

	std::vector<int> sorted = this->_span;
	std::sort(sorted.begin(), sorted.end());
	int min_value = sorted[0];
	int max_value = sorted[sorted.size() - 1];
	
	std::cout << "The longest Span is: ";
	return (max_value - min_value);
}

const char *Span::FullSpanError::what() const throw() {
	return ("The Span you're trying to fill is full");
}

const char *Span::InvalidSize::what() const throw() {
	return ("There is an issue with the size of the Span");
}

void Span::fillSpan(std::vector<int> &nbr_list, int size) {
	if (this->_span.size() + size > this->_size)
		throw InvalidSize();
	this->_span.insert(this->_span.end(), nbr_list.begin(), nbr_list.end());
}
