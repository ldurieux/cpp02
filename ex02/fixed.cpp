#include "fixed.h"

const int Fixed::_fractBits = 8;

Fixed::Fixed() :
	_raw(0)
{
}

Fixed::Fixed(const Fixed &other)
{
	setRawBits(other.getRawBits());
}

Fixed::Fixed(const int value)
{
	_raw = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	float tmp;
	int i;
	float invPower;
	int mask = 1 << (_fractBits - 1);

	_raw = static_cast<int>(value) << _fractBits;
	tmp = value - toInt();
	if (value < 0)
		tmp = (-value) + toInt();
	for (i = 2; mask; mask >>= 1, i <<= 1)
	{
		invPower = 1.0f / static_cast<float>(i);
		if (tmp >= invPower)
		{
			tmp -= invPower;
			_raw |= mask;
		}
	}
	invPower = 1.0f / static_cast<float>(i);
	if (tmp >= invPower / 2)
		_raw++;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return (_raw);
}

void Fixed::setRawBits(const int raw)
{
	_raw = raw;
}

float Fixed::toFloat() const
{
	float res = toInt();
	bool negative = res < 0;
	int mask = 1 << (_fractBits - 1);
	if (res < 0)
		res *= -1;

	for (int i = 2; mask; mask >>= 1, i <<= 1)
		if (_raw & mask)
			res += 1.0f / static_cast<float>(i);
	if (negative)
		return (-res);
	return (res);
}

int Fixed::toInt() const
{
	return (_raw >> _fractBits);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	setRawBits(other.getRawBits());
	return (*this);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_raw < other._raw);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_raw > other._raw);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_raw <= other._raw);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_raw >= other._raw);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_raw == other._raw);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_raw != other._raw);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;

	res._raw = _raw + other._raw;
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;

	res._raw = _raw - other._raw;
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++()
{
	_raw++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed res(*this);

	_raw++;
	return (res);
}

Fixed &Fixed::operator--()
{
	_raw--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed res(*this);

	_raw--;
	return (res);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (out);
}
