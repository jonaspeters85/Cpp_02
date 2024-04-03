#include <iostream>
#include "Fixed.hpp"


int main(void)
{
	Fixed a(1.24f);
	Fixed b(2.24f);
	//float tmp = 1.23f;

    std::cout << "huhu" << std::endl;
	float aa = 12.3;
	float bb = 23.4;
	std::cout << Fixed::min(aa, bb) << std::endl;



	//Fixed const b(Fixed(5.05f) * Fixed(2));
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
