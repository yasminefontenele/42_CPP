
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
        
    private:
        // Jacobsthal number generation
        static std::vector<size_t> generateJacobsthalSequence(size_t n);
        
        template <typename T>
        void fordJohnsonSort(T &container);
        
        // Main sorting algorithm
        template <typename T>
        void mergeInsertionSort(T &container, size_t start, size_t end);
        
        // Helper function to insert elements using Jacobsthal sequence
        template <typename T>
        void insertUsingJacobsthal(T &main_chain, const T &pend);
};


#endif


