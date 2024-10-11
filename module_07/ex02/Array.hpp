#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>

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

template <class T>
class Array {
private:
	T *array;
	int arraySize;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &array);
	Array &operator=(const Array &array);
	~Array();
	int size() const;
	T &operator[](int index) const;
	class OutOfLimits: public std::exception {
		const char *what() const throw();
	};
};

template <class T>
Array<T>::Array() {
	this->array = NULL;
	this->arraySize = 0;
	std::cout << "Array: Default constructor called" << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->arraySize = n;
	std::cout << "Array: Parameterized constructor called" << std::endl;
}

template <class T>
Array<T>::Array(const Array &array) {
	T *cpy = new T[array.arraySize];
	for (int i; i < array.arraySize; i++)
		cpy[i] = array[i];
	this->array = cpy;
	this->arraySize = array.arraySize;
	std::cout << "Array: Copy constructor called" << std::endl;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &array) {
	if (this->array)
		delete [] this->array;
	T *cpy = new T[array.arraySize];
	for (int i; i < array.arraySize; i++)
		cpy[i] = array[i];
	this->array = cpy;
	this->arraySize = array.arraySize;
	std::cout << "Array: Copy operator constructor called" << std::endl;
	return (*this);
}

template <class T>
Array<T>::~Array() {
	if (this->array)
		delete [] this->array;
	std::cout << "Array: Destructor called" << std::endl;
}

template <class T>
int Array<T>::size() const {return (this->arraySize);}

template <class T>
T &Array<T>::operator[](int index) const {
	if (index < 0 || index >= this->arraySize)
		throw OutOfLimits();
	// std::cout << "I'm returning: " << this->array[index] << std::endl;
	return (this->array[index]);
}

template <class T>
const char *Array<T>::OutOfLimits::what() const throw() {
	return ("The index you're introducing is not correct");
}

#endif