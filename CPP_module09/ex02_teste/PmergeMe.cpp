#include "PmergeMe.hpp"
#include <climits>
#include <set>
#include <cstdlib>
#include <cctype>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

// Modularização do parsing
bool PmergeMe::parseArguments(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq)
{
    if (argc < 2)
    {
        std::cerr << "Error: insufficient amount of numbers for sorting" << std::endl;
        return false;
    }

    std::set<int> unique_numbers;

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                std::cerr << "Error: Invalid input \"" << argv[i] << "\"" << std::endl;
                return false;
            }
        }

        long num = std::strtol(argv[i], NULL, 10);
        if (num <= 0 || num > INT_MAX)
        {
            std::cerr << "Error: Invalid input \"" << argv[i] << "\"" << std::endl;
            return false;
        }

        if (!unique_numbers.insert(static_cast<int>(num)).second)
        {
            std::cerr << "Error: duplicate numbers are not accepted.\n";
            return false;
        }

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }

    return true;
}

// Jacobsthal
std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> sequence;
    if (n == 0) return sequence;
    sequence.push_back(0);
    if (n == 1) return sequence;
    sequence.push_back(1);

    while (true)
    {
        size_t next = sequence.back() + 2 * sequence[sequence.size() - 2];
        if (next > n) break;
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

    T main_chain, pend;
    for (typename std::vector<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        main_chain.push_back(it->first);
        pend.push_back(it->second);
    }

    bool has_straggler = (size % 2 != 0);
    int straggler = has_straggler ? container[start + size - 1] : 0;

    if (main_chain.size() > 1)
        fordJohnsonSort(main_chain);

    insertUsingJacobsthal(main_chain, pend);

    if (has_straggler)
    {
        typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    std::copy(main_chain.begin(), main_chain.end(), container.begin() + start);
}

template <typename T>
void PmergeMe::insertUsingJacobsthal(T &main_chain, const T &pend)
{
    if (pend.empty())
        return;

    std::vector<size_t> jacob_seq = generateJacobsthalSequence(pend.size());
    std::vector<bool> inserted(pend.size(), false);

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

    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!inserted[i])
        {
            typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i]);
            main_chain.insert(pos, pend[i]);
        }
    }
}

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

    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();
    double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

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
