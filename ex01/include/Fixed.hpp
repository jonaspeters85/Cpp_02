#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <iomanip>
#include <iostream>


class Fixed
{
	protected:

	private:
		int fixedPointValue;
		static const int fractBits = 8;

	public:		
		void	setRawBits(int value);
		int		getRawBits(void);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed(void);
		~Fixed(void);

		Fixed(const int value);
		Fixed(const float value);
		

		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator

};
#endif




