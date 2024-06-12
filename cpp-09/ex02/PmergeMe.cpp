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

void PmergeMe::measureSortTime(const std::vector<int>& input, const std::string& containerName) 
{
    std::vector<int> copy = input;
    std::clock_t start = std::clock();
    mergeInsertSort(copy);
    std::clock_t end = std::clock();
    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC; // calculate the duration in microseconds

    std::cout << "Time to process a range of " << input.size() << " elements with " << containerName << ": " << duration << " microseconds" << std::endl;
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


void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result) {
    size_t leftIndex = 0, rightIndex = 0, resultIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] <= right[rightIndex]) {
            result[resultIndex++] = left[leftIndex++];
        } else {
            result[resultIndex++] = right[rightIndex++];
        }
    }

    while (leftIndex < left.size()) {
        result[resultIndex++] = left[leftIndex++];
    }

    while (rightIndex < right.size()) {
        result[resultIndex++] = right[rightIndex++];
    }
}

// Insertion sort for std::vector
void insertionSort(std::vector<int>& data) {
    for (size_t i = 1; i < data.size(); ++i) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Merge-insert sort for std::vector
void PmergeMe::mergeInsertSort(std::vector<int>& data) {
    if (data.size() <= 1) {
        return;
    }

    if (data.size() <= 10) {
        insertionSort(data);
        return;
    }

    size_t mid = data.size() / 2;
    std::vector<int> left(data.begin(), data.begin() + mid);
    std::vector<int> right(data.begin() + mid, data.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    merge(left, right, data);
}

// Merging function for std::list
void merge(std::list<int>& left, std::list<int>& right, std::list<int>& result) {
    result.clear();
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end()) {
        if (*leftIt <= *rightIt) {
            result.push_back(*leftIt);
            ++leftIt;
        } else {
            result.push_back(*rightIt);
            ++rightIt;
        }
    }

    while (leftIt != left.end()) {
        result.push_back(*leftIt);
        ++leftIt;
    }

    while (rightIt != right.end()) {
        result.push_back(*rightIt);
        ++rightIt;
    }
}

// Insertion sort for std::list
void insertionSort(std::list<int>& data) {
    if (data.size() <= 1) {
        return;
    }

    for (std::list<int>::iterator it = ++data.begin(); it != data.end(); ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        --j;

        while (j != data.begin() && *j > key) {
            std::list<int>::iterator next = j;
            ++next;
            *next = *j;
            --j;
        }

        if (*j > key) {
            std::list<int>::iterator next = j;
            ++next;
            *next = *j;
            *j = key;
        } else {
            std::list<int>::iterator next = j;
            ++next;
            *next = key;
        }
    }
}

// Merge-insert sort for std::list
void PmergeMe::mergeInsertSort(std::list<int>& data) {
    if (data.size() <= 1) {
        return;
    }

    if (data.size() <= 10) {
        insertionSort(data);
        return;
    }

    std::list<int>::iterator mid = data.begin();
    std::advance(mid, data.size() / 2);
    std::list<int> left(data.begin(), mid);
    std::list<int> right(mid, data.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    data.clear();
    merge(left, right, data);
}

