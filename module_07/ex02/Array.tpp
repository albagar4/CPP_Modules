#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	this->array = NULL;
	std::cout << "Array: Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	std::cout << "Array: Parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &array) {
	if (this->array)
		delete [] this->array;
	T *cpy = new T[array.size()];
	for (int i; i < array.size(); i++)
		cpy[i] = array[i];
	this->array = cpy;
	std::cout << "Array: Copy constructor called"<< std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &array) {
	if (this->array)
		delete [] this->array;
	T *cpy = new T[array.size()];
	for (int i; i < array.size(); i++)
		cpy[i] = array[i];
	this->array = cpy;
	std::cout << "Array: Copy assignment operator called"<< std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	if (this->array)
		delete [] this->array;
	std::cout << "Array: Destructor called" << std::endl;
}

template <typename T>
int Array<T>::size() const {
int size = 0;
	for (int i = 0; this->array; i++)
		size++;
	return (size);
}

template <typename T>
T &Array<T>::operator[](int index) const {
	try {
		if (index >= 0 && index <= this->size())
			return (this->array[index]);
	}
	catch (std::exception &e) {
		std::cout << "The index you're introducing is not valid" << std::endl;
	}
}

#endif