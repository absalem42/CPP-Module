#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void calculate(std::string& str);
        bool isOperator(const std::string& str);
};




#endif
