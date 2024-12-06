/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:55:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 13:15:59 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &other)
{
    if(this != &other)
        AMateria::operator=(other);
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}