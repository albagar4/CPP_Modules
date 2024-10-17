#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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
#include <stack>
#include <deque>

#define RED    "\033[0;31m"
#define BRED    "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET    "\033[0m"
#define RNL    "\033[0m\n"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY "\033[1;30m"
#define PURPLE "\033[35m"
#define LGRAY "\033[0;37m"
#define BOLD "\033[1;37m"

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
public:
	MutantStack() {};
	MutantStack(const MutantStack &mutantStack);
	MutantStack &operator=(const MutantStack &mutantStack);
	~MutantStack() {};
	typename Container::iterator begin();
	typename Container::iterator end();
	T &operator[](int index) const;
	typedef typename Container::iterator iterator;
	typedef typename std::stack<T, Container>::container_type container_type;
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &mutantStack): std::stack<T, Container>(mutantStack) {}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &mutantStack) {
	if (this != &mutantStack) {
		std::stack<T, Container>::operator=(mutantStack);
	}
	return (*this);
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin() {
	return (this->c.begin());
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end() {
	return (this->c.end());
}
template <typename T, typename Container>
T &MutantStack<T, Container>::operator[](int index) const {
	return (this->c[index]);
}

#endif