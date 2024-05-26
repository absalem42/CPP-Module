#include "iter.hpp"


int main() 
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "int array: ";
    iter(intArray, intLength, print<int>);
    std::cout << std::endl;

    std::string charArray[] = {"Abdullah", "Ahmed", "Ali", "Mohammed"};
    size_t charLength = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "string array: ";
    iter(charArray, charLength, print<std::string>);
    std::cout << std::endl;

    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatLength = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "float array: ";
    iter(floatArray, floatLength, print<float>);
    std::cout << std::endl;

    double doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "double array: ";
    iter(doubleArray, doubleLength, print<double>);
    std::cout << std::endl;

    return 0;
}
