#include "Span.hpp"

int main()
{
    try
    {    
    Span span(5);

    // std::vector<int> arr;
    // for(size_t i = 0; i < 1000000; i++)
    //     arr.push_back(i);
    // span.addNumber(arr.begin(),arr.end());

    span.addNumber(-3);
    span.addNumber(5);
    span.addNumber(30);
    span.addNumber(50);
    span.addNumber(100);
    // span.addNumber(6);
    // span.addNumber(6);
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}