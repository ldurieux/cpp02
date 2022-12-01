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

	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);

	Fixed& operator=(const Fixed& other);

	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

private:
	int _raw;
	static const int _fractBits;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif // FIXED_H
