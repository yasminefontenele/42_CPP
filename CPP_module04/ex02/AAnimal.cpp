/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:21 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 16:35:18 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "Constructor default called in AAnimal" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
    std::cout << "Copy constructor called in AAnimal" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor called in AAnimal" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    if(this != &other)
        type = other.type;
    std::cout << "Copy assignment called in AAnimal" << std::endl;
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << "[generic_AAnimal_makes_a_generic_sound]" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}