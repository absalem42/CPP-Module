#include "Fixed.hpp"
// #include <iostream>
// #include <ostream>

int main( void ) {
	Fixed a;
	Fixed const b(123);
	Fixed const c(42.4242421f);
	// Fixed const d( b );
	std::cout << "b is " << c << std::endl;
	// a = Fixed( 1234.4321f );

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
	return 0;
}