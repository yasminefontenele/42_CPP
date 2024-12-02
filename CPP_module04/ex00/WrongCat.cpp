/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:20 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:20:17 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "Constuctor default called in WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    this->type = "WrongCat";
    std::cout << "Copy constuctor called in WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called in WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if(this != &other)
    {
        WrongAnimal::operator=(other);
        this->type = "WrongCat";
    }
    std::cout << "Copy assignment called in WrongCat" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "[Wrong_cat_sound]" << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}