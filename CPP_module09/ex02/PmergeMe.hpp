
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iomanip> // Para std::fixed e std::setprecision

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        void sortAndMeasure(std::vector<int> &vec, std::deque<int> &deq);
        
    private:
        void fordJohnsonSort(std::vector<int> &arr);
        void fordJohnsonSort(std::deque<int> &arr);
        template <typename T>
        void mergeInsertionSort(T &arr);// to encapsulate the Ford-Johnson Sort logic and facilitate implementation in different containers
};

#endif

