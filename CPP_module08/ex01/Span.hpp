#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>//sort, min_element, max_element
#include <stdexcept>

class Span
{
    private:
        unsigned int _maxSize;//Maximum Span Capacity
        std::vector<int> _numbers;//Container to store numbers

    public:
        Span(unsigned int maxSize);
        ~Span();

        void addNumber(int num); // Add a single number
        int shortestSpan() const;// Calculates the smallest range
        int longestSpan() const; // Calculates the largest range

        //Extra method: Add a range of numbers
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class SpanFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();//virtual so it can be overwritten
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
