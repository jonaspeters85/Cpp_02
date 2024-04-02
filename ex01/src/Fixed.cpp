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
    {
		fixedPointValue = other.getRawBits();
		//this->setRawBits(other.getRawBits());
	}

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

// ******* Member Functions **********

void Fixed::setRawBits(int value)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = value;
};

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
};

// fixed point value to floating point value
float Fixed::toFloat(void) const
{
	//return static_cast<float>(getRawBits()) / (1 << fractBits);
	return static_cast<float>(fixedPointValue)/ (1 << fractBits);
}

// fixed point value to int
int Fixed::toInt(void) const
{
	//int t= Fixed::getRawBits();
	//return (getRawBits() >> fractBits);
	return fixedPointValue >> fractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat(); 
	return os;
}