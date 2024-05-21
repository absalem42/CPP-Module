#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>
ScalarConverter::ScalarConverter() 
{

}
ScalarConverter::ScalarConverter(const  ScalarConverter& other) 
{ 
    (void) other; 
}
ScalarConverter& ScalarConverter::operator=(const  ScalarConverter& rhs) 
{ 
    (void) rhs; 
    return (*this); 
}
ScalarConverter::~ScalarConverter() 
{

}

static void printDouble(std::string& input)
{
	try
	{
		double d = std::stod(input);
		if (std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(d))
			std::cout << "double: inf" << std::endl;
		else
		{
			std::cout << "double: " << d;
			if (d == static_cast<int>(d))
				std::cout << ".0";
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

static void printFloat(std::string& input)
{
	try
	{
		float f = std::stof(input);
		if (std::isnan(f))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(f))
			std::cout << "float: inff" << std::endl;
		else
		{
			std::cout << "float: " << f;
			if (f == static_cast<int>(f))
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

static void printInt(const std::string& input)
{
    try
    {
        int i = std::stoi(input);
        char c = static_cast<char>(i);

        std::cout << "char: ";
        if (isprint(c))
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
}

static void printChar(char c)
{
    // Check if the character is printable
    if (isprint(c))
    {
        std::cout << "char: '" << c << "'" << std::endl;
    }
    // Check if the character is non-displayable
    else if (static_cast<unsigned char>(c) >= 128)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    // If neither, then the character is impossible
    else
    {
        std::cout << "char: Impossible" << std::endl;
    }
}

static int validate_input(std::string input)
{
    // Check for spaces
    if (input.find(' ') != std::string::npos) {
        std::cout << "Space found!" << std::endl;
        return 1;
    }

    // Check for invalid literals
    if (input == "-inf" || input == "+inf" || input == "inf" ||
        input == "-inff" || input == "+inff" || input == "inff" ||
        input == "nan" || input == "nanf" || input == "-nan" || input == "-nanf") {
        return 0;
    }

    // Check for multiple decimal points or ending with a decimal point
    int decimalCount = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == '.') {
            decimalCount++;
        }
    }
    if (decimalCount > 1 || input[input.length() - 1] == '.') {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    // Remove leading '+' or '-' sign
    if (input[0] == '-' || input[0] == '+') {
        input.erase(0, 1);
    }

    // Remove 'f' at the end, if preceded by a '.'
    if (input[input.length() - 1] == 'f') {
        input.erase(input.length() - 1);
        if (input[input.length() - 1] == '.') {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
    }

    // Check if input contains only digits and '.' characters
    for (size_t i = 0; i < input.length(); ++i) {
        if (!isdigit(input[i]) && input[i] != '.') {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
    }

    return 0; // Input is valid
}

void ScalarConverter::convert(std::string input)
{
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		printChar(input[0]);
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" <<std::endl;
		return ;
	}
	if (validate_input(input))
		return ;
	printInt(input);
	printFloat(input);
	printDouble(input);
}
