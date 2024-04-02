#include "../include/Fixed.hpp" 

Fixed::Fixed(void)
    : fixedPointValue(0)
{
   	std::cout << "Default constructor called " << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());

	return *this;
}

Fixed::Fixed(const int value)
{
	(void) value;
	std::cout << "Int constructor called " << value << std::endl;

	this->setRawBits(value << fractBits);
}

Fixed::Fixed(const float value)
{
	(void) value;
	std::cout << "Float constructor called " << value << std::endl;

	this->fixedPointValue = static_cast<int>(roundf(value * (1 << fractBits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat(); 
	return os;
}

// ******* Member Functions **********

void Fixed::setRawBits(int value)
{
	this->fixedPointValue = value;
};

int Fixed::getRawBits(void) const
{
	return (this->fixedPointValue);
};

// fixed point value to floating point value
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->getRawBits())/ (1 << fractBits);
}

// fixed point value to int
int Fixed::toInt(void) const
{
	return (this->getRawBits() >> fractBits);
}

