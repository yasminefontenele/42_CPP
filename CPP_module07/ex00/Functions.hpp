
#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

template <typename T>
T swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
    return a;
}

template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

#endif