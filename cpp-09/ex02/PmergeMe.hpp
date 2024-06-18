#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <climits>
#include <algorithm>
#include <list>
#include <utility>
#include <iomanip>

class PmergeMe
{
private:
        std::vector<int> vec;
		std::list<int> lst;
public:
    PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();

    static void printVector(const std::vector<int>& data);
    static void printList(const std::list<int>& data);



    
};

void mergeInsertionSort(std::vector<int>& unsortedList);
void mergeInsertionSort(std::list<int>& unsortedList);



#endif