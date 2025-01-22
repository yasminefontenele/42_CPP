#include <iostream>
#include "iter.hpp"

// Funções simples para teste
void printInt(int x) {
    std::cout << x << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

template <typename T>
void increment(T& x) {
    x++;
}

int main()
{
    // Teste com array de inteiros
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArraySize, printInt);
    std::cout << "\n";

    iter(intArray, intArraySize, increment<int>);
    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, printInt);
    std::cout << "\n";

    // Teste com array de strings
    std::string stringArray[] = {"Hello", "World", "C++"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original stringArray: ";
    iter(stringArray, stringArraySize, printString);
    std::cout << "\n";

    return 0;
}
