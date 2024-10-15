#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
// #include <map>
// #include <set>
// #include <stack>
// #include <queue>
// #include <iterator>
// #include <functional>
// #include <memory>
// #include <utility>
// #include <deque>
// #include <unordered_map>

class Span {
private:
	unsigned int _size;
	std::vector<int> _span;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &span);
	Span &operator=(const Span &span);
	~Span();
	void addNumber(int nbr);
	void shortestSpan(void);
	void longestSpan(void);
	class FullSpanError: public std::exception {
		const char *what() const throw();
	};
	class InvalidSize: public std::exception {
		const char *what() const throw();
	};
};

#endif