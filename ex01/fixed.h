#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat() const;
	int toInt() const;

	Fixed& operator=(const Fixed& other);

private:
	int _raw;
	static const int _fractBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_H
