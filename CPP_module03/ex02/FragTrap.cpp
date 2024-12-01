/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:22:17 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/01 18:28:09 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constuctor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap copy assigment operator called for " << this->name << std::endl;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " requests a positive high five! o/" << std::endl;
}