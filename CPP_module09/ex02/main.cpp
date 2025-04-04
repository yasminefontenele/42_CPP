
#include "PmergeMe.hpp"
#include <climits>
#include <cctype>

bool isAllDigits(const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: insufficient amount of numbers for sorting" << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    
    for (int i = 1; i < argc; i++)
    {
        if (!isAllDigits(argv[i]))
        {
            std::cerr << "Error: Invalid input \"" << argv[i] << "\"" << std::endl;
            return 1;
        }
        
        if (argv[i][0] == '-')
        {
            std::cerr << "Error: negative numbers are not allowed" << std::endl;
            return 1;
        }
        
        char *endptr;
        long num = std::strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0' || num <= 0 || num > INT_MAX)
        {
            std::cerr << "Error: Invalid input \"" << argv[i] << "\"" << std::endl;
            return 1;
        }
        
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
    
    PmergeMe sorter;
    sorter.sortAndMeasure(vec, deq);
    
    return 0;
}
