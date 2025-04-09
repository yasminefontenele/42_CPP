#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

class RPN
{
    public:
        RPN();
        RPN(const RPN& other);
        ~RPN();
        RPN& operator=(const RPN& other);

        double tokenization(const std::string& expression);

        class InvalidExpressionException : public std::exception
        {
            private:
                std::string _msg;
            public:
                InvalidExpressionException(const std::string& msg = "Error") : _msg(msg) {}
                virtual ~InvalidExpressionException() throw() {}
                virtual const char* what() const throw() { return _msg.c_str(); }
        };

    private:
        std::stack<double> _stack;
        void _executeOperator(char op);
};

#endif