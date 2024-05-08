#include "Bureaucrat.hpp"

int main() 
{
    try 
    {
        Bureaucrat b("John", 50);
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.decrement();
        std::cout << b << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
