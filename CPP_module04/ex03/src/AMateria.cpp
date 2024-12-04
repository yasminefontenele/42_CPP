/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:55:15 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/04 11:28:19 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &other)
{
     *this = other;
}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other)
{
    if(this != &other)
        type = other.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "Generic use of AMateria on " << target.getName() << std::endl;
}