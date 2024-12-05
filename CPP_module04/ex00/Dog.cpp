/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:48 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 18:15:31 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Constructor default called in Dog" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->type = "Dog";
    std::cout << "Copy constuctor called in Dog" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called in Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        this->type = "Dog";
    }

    std::cout << "Copy assignment called in Dog" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Wooooof woof!" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}
