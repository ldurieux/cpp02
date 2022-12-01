#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed& operator=(const Fixed& other);

private:
	int _raw;
	static const int _fractBits;
};

#endif // FIXED_H
