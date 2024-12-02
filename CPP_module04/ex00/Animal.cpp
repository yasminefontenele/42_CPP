/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:21 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:57:06 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Constructor default called in Animal" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Copy constructor called in Animal" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destructor called in Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if(this != &other)
        type = other.type;
    std::cout << "Copy assignment called in Animal" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "[generic_animal_makes_a_generic_sound]" << std::endl;
}