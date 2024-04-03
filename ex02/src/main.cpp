#include <iostream>
#include "Fixed.hpp"


int main(void)
{
	Fixed a(1.24f);
	Fixed b(1.24f);
	//float tmp = 1.23f;

    std::cout << "huhu" << std::endl;
	std::cout << (--a) << std::endl;
	std::cout << (a) << std::endl;


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
