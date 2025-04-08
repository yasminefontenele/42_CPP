
/*
For test purposes: ./PmergeMe $(shuf -i 1-10000 -n 3000 | tr "\n" " ")
*/

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    std::vector<int> vec;
    std::deque<int> deq;

    if (!PmergeMe::parseArguments(argc, argv, vec, deq))
        return 1;

    PmergeMe sorter;
    sorter.sortAndMeasure(vec, deq);

    return 0;
}

