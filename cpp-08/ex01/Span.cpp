#include "Span.hpp"


Span::Span() {}

Span::Span(const unsigned int& size) : maxSize(size) {}

Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() { numbers.clear(); }

void Span::addNumber(const unsigned int& num)
{
    if(numbers.size() >= maxSize)
        throw std::runtime_error("the span full");
    numbers.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if(numbers.size() < 2)
        throw std::runtime_error("no span");
    
    std::vector<int> vec = numbers;
    std::sort(vec.begin(), vec.end());
 
    unsigned int min = vec[1] - vec[0];
    for (size_t i = 1; i < vec.size() - 1; ++i)
    {
        unsigned int span = vec[i + 1] - vec[i];
        if (span < min)
            min = span;
    }
    return min;
}

unsigned int Span::longestSpan() const
{
    if(numbers.size() < 2)
        throw std::runtime_error("no span");
    
    std::vector<int> vec = numbers;
    std::sort(vec.begin(), vec.end());

    unsigned int longDis = vec[vec.size()-1] - vec[0];
    return(longDis);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    unsigned int dist = std::distance(begin, end);

    if(dist + numbers.size() > maxSize)
        throw std::runtime_error("you cannot add more than maxsize");
    numbers.insert(numbers.end(), begin, end);
}