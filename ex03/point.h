#ifndef POINT_H
#define POINT_H

#include "fixed.h"

class Point
{
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& point);
	~Point();

	Point& operator=(const Point& other);

	const Fixed& x() const;
	const Fixed& y() const;

private:
	const Fixed	_x;
	const Fixed	_y;
};

#endif // POINT_H
