#include "Span.hpp"

//from subject
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

//my main
/*#include <cstdlib> // Para std::rand e std::srand
#include <ctime>   // Para std::time

int main()
{
    std::srand(std::time(0)); //Initialize the random number generator

    // Creates a Span with capacity for 10,000 numbers
    Span span(10000);

    // Add 10,000 random numbers to the Span
    for (int i = 0; i < 9997; i++)
    {
        span.addNumber(std::rand() % 10000);
    }

    // Tests the smallest and largest range
    try
    {
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::vector<int> extraNumbers;
    extraNumbers.push_back(42);
    extraNumbers.push_back(24);
    extraNumbers.push_back(12);
    extraNumbers.push_back(6);

   try
   {
        for (std::vector<int>::iterator it = extraNumbers.begin(); it != extraNumbers.end(); ++it)
        {
            try
            {
                span.addNumber(*it);// Try to add the number to the Span
                std::cout << "Number added: " << *it << std::endl;
            }
            catch (const Span::SpanFullException &e)
            {
                std::cerr << "Failed to add number " << *it << ": " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}*/