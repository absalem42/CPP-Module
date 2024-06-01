#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>


template<typename T>
int easyfind(T& container, int find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), find);
	if(it != container.end())
		return (*it);
	throw std::runtime_error("Value not found in container");
}

#endif