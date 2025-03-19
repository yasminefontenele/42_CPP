#include "Span.hpp"

Span::Span(unsigned int maxSize) : _maxSize(maxSize) {}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    _numbers.push_back(num);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> sorted = _numbers; //Copy so as not to alter the original
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;//Updates smallest range
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw Span::NotEnoughNumbersException();

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t rangeSize = std::distance(begin, end);
    if (_numbers.size() + rangeSize > _maxSize)
        throw SpanFullException();
    _numbers.insert(_numbers.end(), begin, end);
}

const char* Span::SpanFullException::what() const throw()
{
    return "Span is full!";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to calculate span!";
}