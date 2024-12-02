/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:48 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 16:46:51 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Constructor default called in Dog" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
    this->brain = new Brain(*other.brain);
    this->type = "Dog";
    std::cout << "Copy constructor called in Dog" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Destructor called in Dog" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        AAnimal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);// Deep copy
        this->type = other.type;
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

Brain *Dog::getBrain() const
{
    return brain;
}
