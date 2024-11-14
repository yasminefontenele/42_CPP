/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catalog.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:12:44 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/14 16:23:16 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

bool isValidPhoneNumber(const std::string &phoneNumber)
{
    size_t startIndex = 0;

    if (!phoneNumber.empty() && phoneNumber[0] == '+')
        startIndex = 1;
    for (size_t i = startIndex; i < phoneNumber.length(); i++)
    {
        if (!isdigit(phoneNumber[i]))
            return false;
    }
    return true;
}

int main()
{
    Phonebook phonebook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook! :D" << std::endl;
    
    while (1)
    {
        std::cout << "Please, enter a command [ADD, SEARCH, EXIT]: ";
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            while (!isValidPhoneNumber(phoneNumber))
            {
                std::cout << "Invalid phone number! Please enter a valid one(only numbers are accepted): ";
                std::getline(std::cin, phoneNumber);
            }
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);

            if (firstName.empty() || lastName.empty() || nickname.empty() || 
                phoneNumber.empty() || darkestSecret.empty())
            {
                std::cout << "Sorry, to save the contact you MUST fill all the fields." << std::endl;
            }
            else
                phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
            std::cout << "Enter the index of the contact to view details: ";
            int index;
            std::cin >> index;
            std::cin.ignore();//limpar o buffer do teclado antes de chamar getline novamente
            phonebook.printContact(index);

        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command! Please enter ADD, SEARCH or EXIT." << std::endl;
    }
    return 0;
}