#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{ 
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other; return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> sequence;
    if (n == 0)
        return sequence;
    
    sequence.push_back(0);
    if (n == 1)
        return sequence;
    
    sequence.push_back(1);
    
    while (true)
    {
        size_t next = sequence.back() + 2 * sequence[sequence.size() - 2];
        if (next > n)
            break;
        sequence.push_back(next);
    }
    return sequence;
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &container)
{
    if (container.size() <= 1)
        return;
    mergeInsertionSort(container, 0, container.size());
}

template <typename T>
void PmergeMe::mergeInsertionSort(T &container, size_t start, size_t end)
{
    size_t size = end - start;
    if (size <= 1) return;

    //Create pairs and sort them
    size_t pair_count = size / 2;
    std::vector<std::pair<int, int> > pairs;
    
    for (size_t i = start; i < start + pair_count * 2; i += 2)
    {
        if (container[i] < container[i + 1])
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        else
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
    }

    std::sort(pairs.begin(), pairs.end());

    //Create main chain and pend elements
    T main_chain;
    T pend;
    
    for (typename std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); 
         it != pairs.end(); ++it)
    {
        main_chain.push_back(it->first);
        pend.push_back(it->second);
    }

    //Handle straggler if odd number of elements
    bool has_straggler = (size % 2 != 0);
    int straggler = has_straggler ? container.back() : 0;

    //Recursively sort the main chain
    if (main_chain.size() > 1)
        fordJohnsonSort(main_chain);

    //Insert pend elements using Jacobsthal sequence
    insertUsingJacobsthal(main_chain, pend);

    // Insert straggler if exists
    if (has_straggler)
    {
        typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    // Copy the sorted elements back to the original container
    std::copy(main_chain.begin(), main_chain.end(), container.begin() + start);
}

template <typename T>
void PmergeMe::insertUsingJacobsthal(T &main_chain, const T &pend)
{
    if (pend.empty())
        return;

    std::vector<size_t> jacob_seq = generateJacobsthalSequence(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    // Jk−1
    for (size_t k = 1; k < jacob_seq.size(); ++k)
    {
        size_t current_jacob = jacob_seq[k];
        size_t prev_jacob = jacob_seq[k - 1];

        for (size_t i = prev_jacob - 1; i < current_jacob - 1; ++i)
        {
            if (i < pend.size() && !inserted[i])
            {
                typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i]);
                main_chain.insert(pos, pend[i]);
                inserted[i] = true;
            }
        }
    }

    // Insert any remaining elements
    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!inserted[i]) {
            typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i]);
            main_chain.insert(pos, pend[i]);
        }
    }
}

// Explicit template instantiation
template void PmergeMe::fordJohnsonSort<std::vector<int> >(std::vector<int> &);
template void PmergeMe::fordJohnsonSort<std::deque<int> >(std::deque<int> &);
template void PmergeMe::mergeInsertionSort<std::vector<int> >(std::vector<int> &, size_t, size_t);
template void PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int> &, size_t, size_t);
template void PmergeMe::insertUsingJacobsthal<std::vector<int> >(std::vector<int> &, const std::vector<int> &);
template void PmergeMe::insertUsingJacobsthal<std::deque<int> >(std::deque<int> &, const std::deque<int> &);

void PmergeMe::sortAndMeasure(std::vector<int> &vec, std::deque<int> &deq)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    std::cout << std::endl;
    
    // Measure time for vector
    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();
    double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    // Measure time for deque
    start = clock();
    fordJohnsonSort(deq);
    end = clock();
    double timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector: " 
              << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque: " 
              << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}