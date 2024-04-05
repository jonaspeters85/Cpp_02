#include "../include/Fixed.hpp" 

Fixed::Fixed(void)
    : fixedPointValue(0)
{
   	//std::cout << "Default constructor called " << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	(void)other;
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());

	return *this;
}

Fixed::Fixed(const int value)
{
	(void) value;
	//std::cout << "Int constructor called " << value << std::endl;

	this->setRawBits(value << fractBits);
}

Fixed::Fixed(const float value)
{
	(void) value;
	//std::cout << "Float constructor called " << value << std::endl;

	this->fixedPointValue = static_cast<int>(roundf(value * (1 << fractBits)));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
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



// ++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++        New Operators        +++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++

// **********************************************
// ****       >, <, >=, <=, == and !=        ****
// **********************************************

bool Fixed::operator>(const Fixed &other) const
{
    if (this->toFloat() > other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->toFloat() >= other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->toFloat() == other.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (this->toFloat() != other.toFloat())
		return true;
	else
		return false;
}

// **********************************************
// *****          +, -, *, and /            *****
// **********************************************

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return  Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (this->toFloat() / other.toFloat());
}


// ********************************************************************************************
// *****       pre-increment and post-increment, pre-decrement and post-decremen          *****
// ********************************************************************************************

Fixed &Fixed::operator++(void) 		// pre-inc
{
	//std::cout << "pre - inc" << std::endl;
	// float tmp = this->toFloat();
	// tmp++;
	// this->fixedPointValue = static_cast<int>(roundf(tmp * (1 << fractBits)));
    
	this->fixedPointValue++;
	
	return *this;
}


Fixed Fixed::operator++(int) 		// post-inc
{
	//std::cout << "post - inc" << std::endl;
    // Fixed copy(*this);
	// float tmp = this->toFloat();
	// tmp++;
	// this->fixedPointValue = static_cast<int>(roundf(tmp * (1 << fractBits)));
    
	Fixed copy(*this);
	this->fixedPointValue++;
	
	return copy;
}

Fixed &Fixed::operator--(void) 		// pre-dec
{
	//std::cout << "pre - dec" << std::endl;

	// float tmp = this->toFloat();
	// tmp--;
	// this->fixedPointValue = static_cast<int>(roundf(tmp * (1 << fractBits)));
    
	this->fixedPointValue--;
	
	return *this;
}


Fixed Fixed::operator--(int) 		// post-dec
{
	//std::cout << "post - dec" << std::endl;
    // Fixed copy(*this);
	// float tmp = this->toFloat();
	// tmp--;
	// this->fixedPointValue = static_cast<int>(roundf(tmp * (1 << fractBits)));
    
	Fixed copy(*this);
	this->fixedPointValue--;
	
	return copy;
}


// *********************************
// *****       Min Max         *****
// *********************************

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}
