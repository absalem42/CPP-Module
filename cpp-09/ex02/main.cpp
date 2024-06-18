#include "PmergeMe.hpp"

bool isPositiveInteger(const char* str) 
{
    for (int i = 0; str[i] != '\0'; ++i) 
    {
        if (!isdigit(str[i])) 
        {
            return false;
        }
    }
    return std::atoi(str) > 0;
}

int main(int argc, char **argv) 
{
    if (argc < 2) 
    {
        std::cerr << "Error: No input provided" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 1; i < argc; ++i) {
        if (!isPositiveInteger(argv[i])) 
        {
            std::cerr << "Error: Non-positive integer or invalid input" << std::endl;
            return 1;
        }
        int num = atoi(argv[i]);
        vec.push_back(num);
        lst.push_back(num);
    }

    std::cout << "Before: ";
    PmergeMe::printVector(vec);

    // Timing the sort for std::vector
    clock_t start_vec = clock();
    mergeInsertionSort(vec);
    clock_t end_vec = clock();
    double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;


    clock_t start_lst = clock();
    mergeInsertionSort(lst);
    clock_t end_lst = clock();
    double elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;

    // Display the sorted sequence
    std::cout << "After: ";
    PmergeMe::printVector(vec);

    // Display the timing results
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(7) << elapsed_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << std::fixed << std::setprecision(7) << elapsed_lst << " us" << std::endl;
    return 0;
}