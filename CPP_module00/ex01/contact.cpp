/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:11:56 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/14 16:46:43 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

// This function is used to set the value of the contact fields
void Contact::setContactInfo(const std::string &firstName, const std::string &lastName,
                            const std::string &nickname, const std::string &PhoneNumber,
                            const std::string &darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->PhoneNumber = PhoneNumber;
    this->darkestSecret = darkestSecret;
}

// This function is used to get the value of a specific field of the contact
std::string Contact::getField(const std::string &fild) const
{
    if (fild == "firstName")
        return firstName;
    else if (fild == "lastName")
        return lastName;
    else if (fild == "nickname")
        return nickname;
    else if (fild == "PhoneNumber")
        return PhoneNumber;
    else if (fild == "darkestSecret")
        return darkestSecret;
    return "Error";
}