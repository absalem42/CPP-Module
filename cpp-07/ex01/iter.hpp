#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <class T>
void	print(T a)
{
	std::cout << a << " ";
}

template <typename T>
void iter(T *array, size_t length, void (*func)(T a))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    std::cout << std::endl;
}

#endif