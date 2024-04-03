#include "Fixed.hpp" 

Fixed::Fixed(void)
    : fixedPointValue(0)
{
   	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	(void)other;
	std::cout << "Copy constructor called" << std::endl;
	//this->setRawBits(other.getRawBits());
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
    {
		this->setRawBits(other.getRawBits());
	}

	return *this;
}


void Fixed::setRawBits(int value)
{
	this->fixedPointValue = value;
};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
};

