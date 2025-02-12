#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T arr[], int len, void (*f)(T& x))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	iter(const T arr[], int len, void (*f)(const T& x))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void increment(T& a) {
    a++;
}

template <typename T>
void print_array(T& x) {
    std::cout << x << std::endl;
}

#endif