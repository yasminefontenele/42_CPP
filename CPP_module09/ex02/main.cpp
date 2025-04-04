
/*
For test purposes: ./PmergeMe $(shuf -i 1-10000 -n 3000 | tr "\n" " ")
*/

#include "PmergeMe.hpp"
#include <climits>
#include <cctype>
#include <set>

bool isAllDigits(const char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool hasDuplicates(const std::vector<int>& nums)
{
    std::set<int> unique_numbers;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (!unique_numbers.insert(nums[i]).second)
            return true;
    }
    return false;
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

    if (hasDuplicates(vec))
    {
        std::cerr << "Error: duplicate numbers are not accepted.\n";
        return 1;
    }
    
    PmergeMe sorter;
    sorter.sortAndMeasure(vec, deq);
    
    return 0;
}
