/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:24:34 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/08 10:52:50 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string PhoneNumber;
        std::string darkestSecret;
    public:
        void setContactInfo(const std::string &firstName, const std::string &lastName,
                            const std::string &nickname, const std::string &PhoneNumber,
                            const std::string &darkestSecret);
        std::string getField(const std::string &fild) const;
};

#endif