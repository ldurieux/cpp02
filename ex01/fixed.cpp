#include "fixed.h"

const int Fixed::_fractBits = 8;

Fixed::Fixed() :
	_raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
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
	for (i = 2; mask; mask >>= 1, i <<= 1)
	{
		invPower = 1.0f / static_cast<float>(i);
		if (tmp > invPower)
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
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void Fixed::setRawBits(const int raw)
{
	_raw = raw;
}

float Fixed::toFloat() const
{
	float res = toInt();
	int mask = 1 << (_fractBits - 1);

	for (int i = 2; mask; mask >>= 1, i <<= 1)
		if (_raw & mask)
			res += 1.0f / static_cast<float>(i);
	return (res);
}

int Fixed::toInt() const
{
	return (_raw >> _fractBits);
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (out);
}
