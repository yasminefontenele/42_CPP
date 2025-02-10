#include <iostream>
#include "iter.hpp"

int main()
{
    // Teste com array de inteiros
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original intArray: ";
    iter(intArray, intArraySize, print_array);
    std::cout << "\n";

    iter(intArray, intArraySize, increment);
    std::cout << "Incremented intArray: ";
    iter(intArray, intArraySize, print_array);
    std::cout << "\n";

    // Teste com array de strings
    std::string stringArray[] = {"Hello", "World", "C++"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original stringArray: ";
    iter(stringArray, stringArraySize, print_array);
    std::cout << "\n";

    return 0;
}
