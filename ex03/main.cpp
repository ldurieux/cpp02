#include <iostream>
#include "point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point p1(0.0f, 0.0f);
	Point p2(5.0f, 0.0f);
	Point p3(0.0f, 5.0f);

	Point check(1.0f, 1.0f);
	std::cout << bsp(p1, p2, p3, check) << std::endl;
	check = Point(0.0f, 0.0f);
	std::cout << bsp(p1, p2, p3, check) << std::endl;
	check = Point(2.0f, 0.0f);
	std::cout << bsp(p1, p2, p3, check) << std::endl;
	check = Point(0.0f, 2.0f);
	std::cout << bsp(p1, p2, p3, check) << std::endl;
	check = Point(2.25f, 2.25f);
	std::cout << bsp(p1, p2, p3, check) << std::endl;

	return 0;
}
