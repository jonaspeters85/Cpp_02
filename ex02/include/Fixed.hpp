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


		// ****** ex03 ******  
		// 6 comparison operators: >, <, >=, <=, == and !=
		bool operator>(const Fixed &other);
		bool operator<(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator==(const Fixed &other);
		bool operator!=(const Fixed &other);

		// 4 arithmetic operators: +, -, *, and /.
		float operator+(const Fixed &other);
		float operator-(const Fixed &other);
		float operator*(const Fixed &other);
		float operator/(const Fixed &other);

		// pre-increment and post-increment, pre-decrement and post-decremen 
		Fixed &operator++(void);			// pre inc
		Fixed operator++(int);				// post inc

		Fixed &operator--(void);			// pre dec
		Fixed operator--(int);				// post dec

		// min max
		static Fixed 			&min(Fixed &a, Fixed &b);
		static const Fixed		&min(Fixed const &a, Fixed const &b);
		static Fixed 			&max(Fixed &a, Fixed &b);
		static const Fixed 		&max(Fixed const &a, Fixed const &b);



		//Fixed(const std::string& str); 			// Constructor for std::cout << overloading

		Fixed(void);
		~Fixed(void);

		Fixed(const int value);
		Fixed(const float value);
		

		Fixed(const Fixed& other);				// Copy constructor
		Fixed& operator=(const Fixed& other);	// Copy assignment operator

};
#endif




