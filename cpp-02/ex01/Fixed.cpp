#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNumber)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPoint = intNumber * (1 << fractionalBits);
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(floatNumber * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    fixedPoint = copy.fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        fixedPoint = copy.fixedPoint;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	float	floatValue;

	floatValue = fixedPoint * 1.0 / (1 << fractionalBits);
	return (floatValue);
}

int		Fixed::toInt(void) const
{
    int   intValue;

    intValue = fixedPoint / (1 << fractionalBits);
    return (intValue);
}

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
