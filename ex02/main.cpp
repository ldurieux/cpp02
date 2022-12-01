#include <iostream>
#include "fixed.h"

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(-1.25f);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}
