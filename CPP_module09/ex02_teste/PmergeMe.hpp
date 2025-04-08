
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <utility>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortAndMeasure(std::vector<int> &vec, std::deque<int> &deq);

        // Parsing modularizado
        static bool parseArguments(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq);
    
    private:
        static std::vector<size_t> generateJacobsthalSequence(size_t n);

        template <typename T>
        void fordJohnsonSort(T &container);

        template <typename T>
        void mergeInsertionSort(T &container, size_t start, size_t end);

        template <typename T>
        void insertUsingJacobsthal(T &main_chain, const T &pend);
};

#endif
