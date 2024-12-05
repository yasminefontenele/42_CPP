/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:48:42 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 12:14:10 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constuctor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap copy assigment operator called for " << this->name << std::endl;
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if(this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " attack " << target << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " cannot attcak due to low energy or hit points" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode!" << std::endl;
}
