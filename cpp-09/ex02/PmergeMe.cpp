#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this == &other)
        return *this;
    vec = other.vec;
    lst = other.lst;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::printVector(const std::vector<int>& data) 
{
    for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList(const std::list<int>& data) 
{
    for (std::list<int>::const_iterator it = data.begin(); it != data.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void binarySearchInsert(std::vector<int>& mainChain, int b) 
{
   std::vector<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it < b) 
    {
        ++it;
    }
    mainChain.insert(it, b);
}

void mergeSort(std::vector<std::pair<int, int> >& pairs) 
{
    if (pairs.size() <= 1)
        return;

    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::pair<int, int> > right(pairs.begin() + pairs.size() / 2, pairs.end());

    mergeSort(left);
    mergeSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), pairs.begin());
}

void mergeInsertionSort(std::vector<int>& unsortedList) 
{
    std::vector<std::pair<int, int> > pairs;
    int odd = -1;

    for (size_t i = 0; i < unsortedList.size();) 
    {
        if (i + 1 < unsortedList.size()) 
        {
            pairs.push_back(std::make_pair(unsortedList[i], unsortedList[i + 1]));
            i += 2;
        } 
        else 
        {
            odd = unsortedList[i];
            break;
        }
    }
	
    mergeSort(pairs);

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        mainChain.push_back(pairs[i].first);
    }


    int jacobsthal = 1, nextJacobsthal = 3;
    while (!pairs.empty()) 
    {
        if (jacobsthal <= (int)pairs.size()) 
        {
            binarySearchInsert(mainChain, pairs[jacobsthal - 1].second);
            pairs.erase(pairs.begin() + jacobsthal - 1);
        } 
        else 
        {
            jacobsthal = nextJacobsthal;
            nextJacobsthal = (jacobsthal * 2) - (jacobsthal % 2);
        }
    }

    if (odd != -1) 
    {
        binarySearchInsert(mainChain, odd);
    }

    unsortedList = mainChain;
}




void binarySearchInsert(std::list<int>& mainChain, int b) 
{
    std::list<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it < b) 
    {
        ++it;
    }
    mainChain.insert(it, b);
}

void mergeSort(std::list<std::pair<int, int> >& pairs) 
{
    if (pairs.size() <= 1)
        return;

    std::list<std::pair<int, int> > left;
    std::list<std::pair<int, int> > right;

    size_t halfSize = pairs.size() / 2;
    for (size_t i = 0; i < halfSize; ++i) 
    {
        left.push_back(pairs.front());
        pairs.pop_front();

    while (pairs.size() > halfSize) 
    {
        right.push_back(pairs.front());
        pairs.pop_front();
    }

    mergeSort(left);
    mergeSort(right);

    pairs.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(pairs));
}
}

void mergeInsertionSort(std::list<int>& unsortedList) 
{
    std::list<std::pair<int, int> > pairs;
    int odd = -1;

    std::list<int>::iterator it = unsortedList.begin();
    while (it != unsortedList.end()) 
    {
        int current = *it;
        ++it;
        if (it != unsortedList.end()) 
        {
            pairs.push_back(std::make_pair(current, *it));
            ++it;
        } 
        else 
        {
            odd = current;
            break;
        }
    }

    mergeSort(pairs);

    std::list<int> mainChain;
    std::list<std::pair<int, int> >::iterator pairIt = pairs.begin();
    while (pairIt != pairs.end()) 
    {
        mainChain.push_back(pairIt->first);
        ++pairIt;
    }

    int jacobsthal = 1, nextJacobsthal = 3;
    while (!pairs.empty()) 
    {
        if (jacobsthal <= (int)pairs.size()) 
        {
            binarySearchInsert(mainChain, pairs.front().second);
            pairs.pop_front();
        } 
        else 
        {
            jacobsthal = nextJacobsthal;
            nextJacobsthal = (jacobsthal * 2) - (jacobsthal % 2);
        }
    }

    if (odd != -1) 
    {
        binarySearchInsert(mainChain, odd);
    }

    unsortedList = mainChain;
}
