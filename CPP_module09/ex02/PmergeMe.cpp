#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) { (void)other; return *this; }

PmergeMe::~PmergeMe() {}

// To demonstrate the time measurement and sorting
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
    double timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    
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

void PmergeMe::fordJohnsonSort(std::vector<int> &arr)
{
    mergeInsertionSort(arr);
}

void PmergeMe::fordJohnsonSort(std::deque<int> &arr)
{
    mergeInsertionSort(arr);
}


/*
@brief The mergeInsertionSort function is a helper function that implements the merge-insertion sort algorithm
@details It takes a container (vector or deque) as input and sorts it using the merge-insertion sort algorithm
         The function first creates pairs of elements from the input container, then sorts the main sequence
         and inserts the sub-sequence into the main sequence
         The function uses std::lower_bound to find the correct position for each element in the sub-sequence
         Finally, it assigns the sorted main sequence back to the input container
         The function is templated to work with both std::vector and std::deque
*/
template <typename T>
void PmergeMe::mergeInsertionSort(T &arr)
{
    if (arr.size() <= 1)
        return;
    
    // Create pairs of elements
    // The first element of each pair is the maximum, and the second is the minimum
    // This is done to ensure that the first element of each pair is always greater than or equal to the second
    std::vector<std::pair<int, int> > pairs;
    T mainSeq, subSeq;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
        pairs.push_back(std::make_pair(std::max(arr[i], arr[i + 1]), std::min(arr[i], arr[i + 1])));
    
    // We take only the largest numbers of the pairs and put them in mainSeq
    for (size_t i = 0; i < pairs.size(); i++)
        mainSeq.push_back(pairs[i].first);
    
    // If the size of the array is odd, add the last element to the main sequence
    if (arr.size() % 2 != 0)
        mainSeq.push_back(arr.back());
    
    mergeInsertionSort(mainSeq);
    
    for (size_t i = 0; i < pairs.size(); i++)
        subSeq.push_back(pairs[i].second);
    
    //Here, for each number in subSeq we use lower_bound to find the correct position where the number
    //should be inserted inside mainSeq. Then, we use insert to put the number in the right position.
    //This simulates the Insertion Sort part, where we insert the smallest elements already inside the sorted list.
    for (size_t i = 0; i < subSeq.size(); i++)
    {
        typename T::iterator pos = std::lower_bound(mainSeq.begin(), mainSeq.end(), subSeq[i]);

        // Obter o índice correto a partir do iterador
        size_t index = std::distance(mainSeq.begin(), pos);

        // Inserir no índice correto dentro do deque
        mainSeq.insert(mainSeq.begin() + index, subSeq[i]);
    }
    
    arr.assign(mainSeq.begin(), mainSeq.end());
}