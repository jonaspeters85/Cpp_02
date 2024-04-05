#include <iostream>
#include "Fixed.hpp"


int main(void) 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;


	// const Fixed c(1.23f);
	// const Fixed d(1.24f);

	// std::cout << (c < d) << std::endl;
	// std::cout << (c > d) << std::endl;
	// std::cout << (c <= d) << std::endl;
	// std::cout << (c >= d) << std::endl;
	// std::cout << (c != d) << std::endl;


	return 0;
}
