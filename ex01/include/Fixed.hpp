#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	protected:

	private:
		int fixedPointValue;
		static const int fractBits = 8;

	public:		
		void	setRawBits(int const value);
		int		getRawBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;


    	// Overloaded insertion operator as a member function
    	friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);

		//Fixed(const std::string& str); 			// Constructor for std::cout << overloading

		Fixed(void);
		~Fixed(void);

		Fixed(const int value);
		Fixed(const float value);
		

		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator

};
#endif




