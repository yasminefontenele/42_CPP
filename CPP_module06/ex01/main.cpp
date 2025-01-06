/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:50:02 by yfontene          #+#    #+#             */
/*   Updated: 2025/01/06 14:30:32 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

/*
int main()
{
    // Criando um objeto Data e inicializando
    Data data = {42, "Example", 3.14f};

    // Serializando o ponteiro para uintptr_t
    uintptr_t raw = Serializer::serializer(&data);
    std::cout << "Serialized address: " << raw << std::endl;

    // Desserializando o uintptr_t para um ponteiro
    Data* deserialized = Serializer::deserializer(raw);

    // Validando os dados
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;

    // Garantindo que o ponteiro original e desserializado são iguais
    if (deserialized == &data) {
        std::cout << "Success: The deserialized pointer matches the original." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer does not match the original." << std::endl;
    }

    return 0;
}
*/

int main() {
    Data data1 = {1, "First", 10.5f};
    Data data2 = {2, "Second", 20.75f};

    // Serializando os ponteiros
    uintptr_t raw1 = Serializer::serializer(&data1);
    uintptr_t raw2 = Serializer::serializer(&data2);

    std::cout << "Serialized addresses:\n";
    std::cout << "Data1: " << raw1 << "\n";
    std::cout << "Data2: " << raw2 << "\n";

    // Desserializando
    Data* deserialized1 = Serializer::deserializer(raw1);
    Data* deserialized2 = Serializer::deserializer(raw2);

    // Validando os dados
    std::cout << "\nDeserialized Data1:\n";
    std::cout << "ID: " << deserialized1->id << "\n";
    std::cout << "Name: " << deserialized1->name << "\n";
    std::cout << "Value: " << deserialized1->value << "\n";

    std::cout << "\nDeserialized Data2:\n";
    std::cout << "ID: " << deserialized2->id << "\n";
    std::cout << "Name: " << deserialized2->name << "\n";
    std::cout << "Value: " << deserialized2->value << "\n";

    // Verificando se os ponteiros são iguais aos originais
    std::cout << "\nPointer validation:\n";
    std::cout << (deserialized1 == &data1 ? "Data1 matches.\n" : "Data1 does not match.\n");
    std::cout << (deserialized2 == &data2 ? "Data2 matches.\n" : "Data2 does not match.\n");

    return 0;
}