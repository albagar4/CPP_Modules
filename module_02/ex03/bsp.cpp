#include "Point.hpp"

bool slopeCalc(Point const i, Point const j, Point const k){
	Fixed slope_ij;
	Fixed slope_ik;

	slope_ij = (i.getY() - j.getY()) / (i.getX() - j.getX());
	slope_ik = (i.getY() - k.getY()) / (i.getX() - j.getX());
	if ((slope_ij == slope_ik) && ((i.getX() <= k.getX() && k.getX() <= j.getX()) 
		|| (j.getX() <= k.getX() && k.getX() <= i.getX())
		|| (i.getY() <= k.getY() && k.getY() <= j.getY()) 
		|| (j.getY() <= k.getY() && k.getY() <= i.getY())))
		return (true);
	return (false);
}

bool edgeCheck(Point const a, Point const b, Point const c, Point const point){
	if (slopeCalc(a, b, point) || slopeCalc(a, c, point) || slopeCalc(b, c, point))
		return (true);
	return (false);
}

float	areaCalc(Point const i, Point const j, Point const k){
	float area;

	area = (i.getX().toFloat())*(j.getY().toFloat() - k.getY().toFloat());
	area += (j.getX().toFloat())*(k.getY().toFloat() - i.getY().toFloat());
	area += (k.getX().toFloat())*(i.getY().toFloat() - j.getY().toFloat());
	if (area < 0)
		area *= -1;
	return (area);
}

float	totalAreaCalc(Point const a, Point const b, Point const c, Point const point){
	float totalArea;

	totalArea = areaCalc(a, b, point);
	totalArea += areaCalc(a, c, point);
	totalArea += areaCalc(b, c, point);
	return (totalArea);
}

bool bsp(Point const a,  Point const b, Point const c, Point const point){
	float hArea;
	float rArea;

	if (a == point || b == point || c == point || edgeCheck(a, b, c, point))
		return (false);
	hArea = totalAreaCalc(a, b, c, point);
	rArea = areaCalc(a, b, c);
	if (hArea == rArea)
		return (true);
	return (false);
}
