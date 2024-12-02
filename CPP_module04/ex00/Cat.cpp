/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:20 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:53:19 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Constructor default called in Cat" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->type = "Cat";
    std::cout << "Copy constructor called in Cat" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor called in Cat" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if(this != &other)
    {
        Animal::operator=(other);
        this->type = "Cat";
    } 
    std::cout << "Copy assignment called in Cat" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow Meow!" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}