#include "Fixed.hpp" 

Fixed::Fixed(void)
    : fixedPointValue(0)
{
   	std::cout << "Default constructor called" << std::endl;
}



// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.fixedPointValue);
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
    {
		this->setRawBits(this->getRawBits());
	}

	return *this;
}

Fixed::Fixed(const int value)
{
	(void) value;
}

Fixed::Fixed(const float value)
{
	(void) value;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// ******* Member Functions **********

void Fixed::setRawBits(int value)
{
	this->fixedPointValue = value;
};

int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
};

// fixed point value to floating point value
float Fixed::toFloat(void) const
{
	return (0.f);
}

// fixed point value to int
int Fixed::toInt(void) const
{
	return (0);
}