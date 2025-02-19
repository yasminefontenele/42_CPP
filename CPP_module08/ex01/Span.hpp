#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>//sort, min_element, max_element
#include <stdexcept>

class Span
{
    private:
        unsigned int _maxSize;     // Quantidade máxima de números
        std::vector<int> _numbers; // Container para armazenar os números

    public:
        Span(unsigned int maxSize);
        ~Span();

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        // Método extra: Adicionar um range de números
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class SpanFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();//virtual para poder ser sobrescrito
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
