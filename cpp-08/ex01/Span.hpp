#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
	    unsigned int		maxSize;
	    std::vector<int>	numbers;

    public:
	    Span();
	    Span(const unsigned int& size);
	    Span(const Span &other);
	    Span	&operator=(const Span &other);
	    ~Span();

        void addNumber(const unsigned int& num);
        unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};


#endif