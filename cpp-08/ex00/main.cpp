#include "easyfind.hpp"


int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> deq;

    for (int i = 0; i < 10; i++) 
    {
        vec.push_back(i);
        lst.push_back(i);
        deq.push_back(i);
    }
    try
    {
        std::cout << "Testing vector:" << std::endl;
        std::cout << easyfind(vec, 0) << std::endl;

        std::cout << "\nTesting list:" << std::endl;
        std::cout << easyfind(lst, 5) << std::endl;

        std::cout << "\nTesting deque:" << std::endl;
        std::cout << easyfind(deq, 10) << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

}