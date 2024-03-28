#include "Fixed.hpp" 

Fixed::Fixed(void)
    : fixedPointValue(0)
{
   
}

Fixed::~Fixed(void)
{

}

// Copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
    fixedPointValue = other.getRawBits();
    // Perform deep copy if necessary
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
    {
		// Perform deep copy if necessary
	}
	return *this;
}


void Fixed::setRawBits(int value)
{
	//this->RawBits = value;
};

int Fixed::getRawBits(void)
{
	//return (this->RawBits);
    return 0;
};

