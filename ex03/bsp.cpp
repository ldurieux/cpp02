#include "point.h"
#include <iostream>
#include <cmath>

Fixed triangle_area(const Point& a, const Point& b, const Point& c)
{
	float res = 0.0f;

	res = (
			a.x() * b.y() + b.x() * c.y() + c.x() * a.y()
			- a.y() * b.x() - b.y() * c.x() - c.y() * a.x()
		).toFloat() / 2;

	if (res < 0)
		res *= -1;
	return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed rootArea = triangle_area(a, b, c);

	Fixed area1 = triangle_area(a, b, point);
	Fixed area2 = triangle_area(a, point, c);
	Fixed area3 = triangle_area(point, b, c);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	return (rootArea >= area1 + area2 + area3);
}
