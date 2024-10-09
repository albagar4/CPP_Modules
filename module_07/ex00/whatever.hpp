#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

template <typename T> 
void swap(T &x, T &y) {
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T minValue(T x, T y) {
	if (y <= x)
		return (y);
	return (x);
}

template <typename T>
T maxValue(T x, T y) {
	if (y >= x)
		return (y);
	return (x);
}

#endif
