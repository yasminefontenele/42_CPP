#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
/*typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Value not found in container!");
    }
    return it;// Retorna a posição do valor no container
}*/

typename T::const_iterator easyfind(const T &container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container!");
    }
    std::cout << "Value found: " << *it << std::endl;
    std::cout << "Position is: " << std::distance(container.begin(), it) << std::endl;
    std::cout << std::endl;
    return it;
}

#endif
