#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() 
{
    srand(time(NULL));
    int random = std::rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{   
    if (dynamic_cast<A *> (p))
		std::cout << "I am A" << std::endl;
	else if (dynamic_cast<B *> (p))
		std::cout << "I am B" << std::endl;
	else if (dynamic_cast<C *> (p))
		std::cout << "I am C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &> (p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) 
    {
    }
	try
	{
		B & b = dynamic_cast<B &> (p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) 
    {
    }
	try
	{
		C & c = dynamic_cast<C &> (p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) 
    {
    }
}

int main()
{
    Base*   ptr = generate();
    if (ptr == NULL) {
		std::cout << "Failed to generate object." << std::endl;
		return 1;
	}

	identify(ptr);
	identify(*ptr);
	if (ptr) delete ptr;
	return (0);
}
