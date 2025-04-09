#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

void RPN::_executeOperator(char op)
{
    if (_stack.size() < 2)
        throw InvalidExpressionException("Not enough operands");

    double b = _stack.top();
    _stack.pop();
    double a = _stack.top();
    _stack.pop();

    switch (op)
    {
        case '+': _stack.push(a + b); break;
        case '-': _stack.push(a - b); break;
        case '*': _stack.push(a * b); break;
        case '/':
            if (b == 0)
                throw InvalidExpressionException("Division by zero");
            _stack.push(a / b);
            break;
        default:
            throw InvalidExpressionException("Unknown operator");
    }
}

double RPN::tokenization(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1)
        {
            char c = token[0];
            if (isdigit(c))
                _stack.push(c - '0');
            else if (c == '+' || c == '-' || c == '*' || c == '/')
                _executeOperator(c);
            else
                throw InvalidExpressionException("Invalid character");
        }
        else
        {
            bool isNumber = true;
            for (size_t i = 0; i < token.length(); ++i)
            {
                if (!isdigit(token[i])) {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber)
                throw InvalidExpressionException("Multi-digit number not allowed");
            else
                throw InvalidExpressionException("Invalid token");
        }
    }

    if (_stack.size() != 1)
        throw InvalidExpressionException("Invalid expression format");

    return _stack.top();
}