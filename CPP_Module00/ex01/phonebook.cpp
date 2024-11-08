/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:19:29 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/08 11:19:33 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : index(0) {}

void Phonebook::addContact(const std::string &firstName, const std::string &lastName,
                            const std::string &nickname, const std::string &PhoneNumber,
                            const std::string &darkestSecret)
{
    if (index < 8)
    {
        contacts[index].setContactInfo(firstName, lastName, nickname, PhoneNumber, darkestSecret);
        index++;
    }
    else
    {
        std::cout << "Phonebook is full" << std::endl;
    }
}

void Phonebook::searchContact() const
{
    std::cout   << std::setw(10) << "Index" << "|"
                << std::setw(10) << "First Name" << "|"
                << std::setw(10) << "Last Name" << "|"
                << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < index; i++)
    {
        std::string firstName = contacts[i].getField("firstName");
        std::string lastName = contacts[i].getField("lastName");
        std::string nickname = contacts[i].getField("nickname");

        if (firstName.empty()) break;

        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";

        std::cout   << std::setw(10) << i << "|"
                    << std::setw(10) << firstName << "|"
                    << std::setw(10) << lastName << "|"
                    << std::setw(10) << nickname << std::endl;
    }
}

void Phonebook::printContact(int index) const
{ 
    if (index < 0 || index >= 8 || contacts[index].getField("firstName").empty())
    {
        std::cout << "Error: Invalid contact index" << std::endl;
        return;
    }
    
    std::cout << "First Name: " << contacts[index].getField("firstName") << std::endl;
    std::cout << "Last Name: " << contacts[index].getField("lastName") << std::endl;
    std::cout << "Nickname: " << contacts[index].getField("nickname") << std::endl;
    std::cout << "Phone Number: " << contacts[index].getField("PhoneNumber") << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getField("darkestSecret") << std::endl;
}