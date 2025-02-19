#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"
#include <iostream>

// Construtor padrão
template <typename T>
MutantStack<T>::MutantStack() {}

// Construtor de cópia
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

// Operador de atribuição
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// Métodos begin() e end()
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

#endif

