#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Teste: Array vazio
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Teste: Array com tamanho definido
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        // Teste: Acesso fora dos limites
        try {
            std::cout << intArray[10] << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        // Teste: Copiando arrays
        Array<int> copyArray = intArray;
        std::cout << "Copy array: ";
        for (unsigned int i = 0; i < copyArray.size(); ++i) {
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl;

        // Teste: Array de strings
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";
        std::cout << "String array: ";
        for (unsigned int i = 0; i < stringArray.size(); ++i) {
            std::cout << stringArray[i] << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
