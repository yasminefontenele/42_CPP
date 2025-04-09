#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// checks if the input is valid and fills the vector and deque with the numbers
bool PmergeMe::parseArguments(int argc, char **argv, std::vector<int> &vec, std::deque<int> &deq)
{
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

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> sequence;
    
    if (n == 0) //J(0)
        return sequence;
    sequence.push_back(0);
    
    if (n == 1)//J(1)
        return sequence;
    sequence.push_back(1);

    while (true) // while the next number is less than n
    {
        size_t next = sequence.back() + 2 * sequence[sequence.size() - 2]; // J(n) = J(n-1) + 2 * J(n-2)
        if (next > n)
            break;
        sequence.push_back(next);
    }
    return sequence;
}

// Sorts the vector using the Ford-Johnson algorithm
void PmergeMe::sortVector()
{
    fordJohnsonSort(_vec);
}

// Sorts the deque using the Ford-Johnson algorithm
void PmergeMe::sortDeque()
{
    fordJohnsonSort(_deq);
}


template <typename T>
void PmergeMe::fordJohnsonSort(T &container)
{
    if (container.size() <= 1)
        return;
    mergeInsertionSort(container);
}

template <typename T>
void PmergeMe::mergeInsertionSort(T &container)
{
    if (container.size() <= 1)
        return;
    
    T mainChain;
    T pendings;
    
    //until container size - 1 to ensure that it will process the pairs and not access elements outside the range
    for (size_t i = 0; i < container.size() - 1; i += 2)
    {
        typename T::value_type first = container[i];
        typename T::value_type second = container[i + 1];
        if (first > second)
            std::swap(first, second);
        mainChain.push_back(first);
        pendings.push_back(second);
    }

    if (container.size() % 2 == 1)
        pendings.push_back(container.back());
    
    // Sort the main chain recursively
    mergeInsertionSort(mainChain);

    insertUsingJacobsthal(mainChain, pendings);

    // Merge the main chain and pendings
    container.assign(mainChain.begin(), mainChain.end());
}

template <typename T>
void PmergeMe::insertUsingJacobsthal(T &main_chain, const T &pend)
{
    if (pend.empty())
        return;

    std::vector<size_t> jacob_seq = generateJacobsthalSequence(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    // Insert the first element
    typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[0]);
    main_chain.insert(pos, pend[0]);
    inserted[0] = true;

    for (size_t k = 1; k < jacob_seq.size(); ++k)
    {
        size_t current_jacob = jacob_seq[k];
        size_t prev_jacob = jacob_seq[k - 1];

        for (size_t i = current_jacob; i > prev_jacob; --i)
        {
            if (i - 1 < pend.size() && !inserted[i - 1])
            {
                pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i - 1]);
                main_chain.insert(pos, pend[i - 1]);
                inserted[i - 1] = true;
            }
        }
    }

    // Insert any remaining elements
    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (!inserted[i])
        {
            pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend[i]);
            main_chain.insert(pos, pend[i]);
        }
    }
}

// Explicit template instantiations
template void PmergeMe::fordJohnsonSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::fordJohnsonSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::mergeInsertionSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::mergeInsertionSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::insertUsingJacobsthal<std::vector<int> >(std::vector<int>&, const std::vector<int>&);
template void PmergeMe::insertUsingJacobsthal<std::deque<int> >(std::deque<int>&, const std::deque<int>&);

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