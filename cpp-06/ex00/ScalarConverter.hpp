#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{	
	private:
		ScalarConverter();
		ScalarConverter(const  ScalarConverter& other);
		ScalarConverter& operator=(const  ScalarConverter& rhs);
		~ScalarConverter();
	public:
		static void convert(std::string input );
};




#endif