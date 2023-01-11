#include "point.h"

Point::Point() :
	_x(0),
	_y(0)
{

}

Point::Point(const float x, const float y) :
	_x(x),
	_y(y)
{

}

Point::Point(const Point &point) :
	_x(point._x),
	_y(point._y)
{

}

Point::~Point()
{

}

Point &Point::operator=(const Point &other)
{
	struct Abomination
	{
		Fixed x;
		Fixed y;
	} *abominable;

	abominable = (Abomination *)(void *)this;
	abominable->x = other._x;
	abominable->y = other._y;

	return (*this);
}

const Fixed& Point::x() const
{
	return _x;
}

const Fixed& Point::y() const
{
	return _y;
}
