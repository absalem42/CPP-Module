#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return (*this);
}

RPN::~RPN()
{
}
bool RPN::isOperator(const std::string& str)
{
    return (str == "+" || str == "-" || str == "*" || str == "/");
}


void RPN::calculate(std::string& str) 
{
    for (size_t i = 0; i < str.length(); ++i) 
    {
        char ch = str[i];
        if (std::isdigit(ch)) 
        {
            _stack.push(std::stof(std::string(1, ch)));
        } 
        else if (isOperator(std::string(1, ch))) 
        {
            if (_stack.size() < 2) 
            {
                throw std::runtime_error("Not enough operands");
            }
            float op2 = _stack.top();
            _stack.pop();
            float op1 = _stack.top();
            _stack.pop();
            if (ch == '+') {
                _stack.push(op1 + op2);
            } 
            else if (ch == '-') 
            {
                _stack.push(op1 - op2);
            } 
            else if (ch == '*') 
            {
                _stack.push(op1 * op2);
            } 
            else if (ch == '/') 
            {
                if (op2 == 0) 
                {
                    throw std::runtime_error("Division by zero");
                }
                _stack.push(op1 / op2);
            }
        } 
        else 
        {
            throw std::runtime_error("Invalid character in expression");
        }
    }
    if (_stack.size() != 1) 
    {
        throw std::runtime_error("Invalid expression");
    }

    std::cout << "Result: " << _stack.top() << std::endl;
}