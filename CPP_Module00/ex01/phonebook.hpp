/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:13 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/12 19:18:18 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"
#include <iostream>
#include <iomanip>//para formatação de output 

class Phonebook
{
    private:
        Contact contacts[8];
        int index;
        int totalContacts;
    public:
        Phonebook();
        void addContact(const std::string &firstName, const std::string &lastName,
                        const std::string &nickname, const std::string &PhoneNumber,
                        const std::string &darkestSecret);
        void searchContact() const;
        void printContact(int index) const;
};

#endif