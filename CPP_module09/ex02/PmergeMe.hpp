#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>// for setprecision
#include <utility>// for std::pair
#include <climits>
#include <set>
#include <cstdlib>// for strtol
#include <cctype>// for isdigit

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void sortAndMeasure(std::vector<int> &vec, std::deque<int> &deq);
        void sortVector();
        void sortDeque();

        static bool parseArguments(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq);
    
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        static std::vector<size_t> generateJacobsthalSequence(size_t n);

        template <typename T>
        void mergeInsertionSort(T &container);

        template <typename T>
        void fordJohnsonSort(T &container);

        template <typename T>
        void insertUsingJacobsthal(T &main_chain, const T &pend);
};

#endif