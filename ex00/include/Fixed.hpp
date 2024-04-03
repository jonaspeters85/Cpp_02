#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <iomanip>

class Fixed
{
	protected:

	private:
		int fixedPointValue;
		static const int fractBits = 8;

	public:		
		void setRawBits(int const value);
		int getRawBits(void) const;

    	// Copy constructor
		Fixed(const Fixed& other);

    	// Copy assignment operator
		Fixed& operator=(const Fixed& other);

		Fixed(void);
		~Fixed(void);
};
#endif




