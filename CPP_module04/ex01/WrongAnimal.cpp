/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:20 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:26:30 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Constuctor default called in WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "Copy constuctor called in WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called in WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if(this != &other)
        WrongAnimal::operator=(other);
    std::cout << "Copy assignment called in WrongAnimal" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[Wrong_Animal_sound]" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}