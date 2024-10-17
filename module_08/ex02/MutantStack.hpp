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

template <typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack &mutantStack);
	MutantStack &operator=(const MutantStack &mutantStack);
	~MutantStack();
	T *begin(void);
	T *end(void);
	T &operator[](int index) const;
	typedef typename std::stack<T>::
};

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {
	std::cout << "MutantStack: Default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &mutantStack) {
	std::cout << "MutantStack: Copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &mutantStack) {
	std::cout << "MutantStack: Copy operator constructor called" << std::endl;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack: Destructor called" << std::endl;
}

template <typename T>
T *MutantStack<T>::begin(void) {
	return (this->c.begin());
	// if (this.empty())
	// 	throw EmptyStack();

	// MutantStack cpy = this;
	// for (int i = this.size(); i > 1; i--)
	// 	cpy.pop();
	// return (&cpy.top());
}

template <typename T>
T *MutantStack<T>::end(void) {
	if (this.empty())
		throw EmptyStack();
	return (&this.top());
}

template <typename T>
T &MutantStack<T>::operator[](int index) const {
	if (index < 0 || index > (this.size() - 1))
		throw WrongIndex();
	if (this.empty())
		throw EmptyStack();
	
	MutantStack cpy = this;
	for (int i = (size - 1); i > 0; i--)
	{
		if (i == index)
			return (cpy.top());
		cpy.pop();
	}
	return (NULL);
}

#endif