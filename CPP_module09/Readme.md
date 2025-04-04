# PmergeMe - Ford-Johnson Merge-Insertion Sort Algorithm

![C++](https://img.shields.io/badge/C++-98-blue.svg)

An efficient implementation of the Ford-Johnson Merge-Insertion Sort algorithm in C++98 that handles large sequences of positive integers.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Algorithm Overview](#algorithm-overview)

## Project Description

This project implements the Ford-Johnson algorithm (also known as merge-insertion sort) as required by the 42 School exercise. It demonstrates sorting performance comparison between two different STL containers (vector and deque) while handling up to 3000 different integers.

## Features

- Implements the Ford-Johnson algorithm from Knuth's "Art of Computer Programming"
- Works with two different STL containers (vector and deque)
- Handles up to 3000 different integers
- Comprehensive error handling
- Precise timing measurements
- Extensive test suite

## Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/PmergeMe.git
cd PmergeMe
```

2. Compile the program:
```bash
make
```


3.Basic usage:
```´bash
./PmergeMe <sequence of positive integers>
```

Example:
```bash
./PmergeMe 3 5 9 7 4
```

Expected output:
```bash
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector: 0.00031 us
Time to process a range of 5 elements with std::deque: 0.00014 us
```

## Testing

The project includes an advanced test script that verifies:

- Basic sorting functionality

- Error cases (negative numbers, zeros, non-digits)

- Performance with 3000 random numbers

- Memory leaks with Valgrind

To run tests:
```bash
chmod +x test_pmergeme.sh
./test_PmergeMe.sh
```

## Algorithm Overview


The Ford-Johnson algorithm combines merge and insertion sort techniques:

- Pairing Phase: Create pairs of elements

- Recursive Sorting: Sort the larger elements of each pair

- Insertion Phase: Insert remaining elements using binary search

Key optimizations:

- Jacobsthal numbers for optimal insertion sequence

- Binary search for efficient element placement

- Hybrid approach minimizing comparisons

To better understand the algorithm:


https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
