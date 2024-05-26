#include "Array.hpp"

int main() 
{
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl; 

    Array<int> arrayWithSize(5);
    std::cout << "Size of arrayWithSize: " << arrayWithSize.size() << std::endl;
    for (unsigned int i = 0; i < arrayWithSize.size(); ++i) 
    {
        std::cout << arrayWithSize[i] << " "; 
    }
    std::cout << std::endl;

    Array<int> copiedArray(arrayWithSize);
    std::cout << "Size of copiedArray: " << copiedArray.size() << std::endl;

    Array<int> assignedArray;
    assignedArray = arrayWithSize;
    std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;

    std::cout << "Accessing elements of arrayWithSize: ";
    for (unsigned int i = 0; i < arrayWithSize.size(); ++i) 
    {
        std::cout << arrayWithSize[i] << " ";
    }
    std::cout << std::endl;

    try 
    {
        std::cout << arrayWithSize[5] << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}