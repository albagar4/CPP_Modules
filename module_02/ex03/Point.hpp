#ifndef POINT_HPP
# define POINT_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdbool.h>
#include <cmath>
#include "Fixed.hpp"

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

class Point{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &cpy);
	Point& operator=(const Point& right_value);
	bool operator==(const Point& right_value) const;

	~Point();
	Fixed getX(void) const;
	Fixed getY(void) const;
};

std::ostream& operator<<(std::ostream& os, const Point& obj);
bool slopeCalc(Point const i, Point const j, Point const k);
bool edgeCheck(Point const a, Point const b, Point const c, Point const point);
float areaCalc(Point const i, Point const j, Point const z);
float totalAreaCalc(Point const a, Point const b, Point const c, Point const point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif