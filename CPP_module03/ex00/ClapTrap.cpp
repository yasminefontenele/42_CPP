/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:08:12 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 11:55:14 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for " << name << std::endl;    
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy called for " << name << std::endl; 
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called for " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << name << " has " << energyPoints << " of energy points" << std::endl; 
    if(energyPoints <= 0)
    {
        std::cout << name << " has no energy left" << std::endl;
        return;
    }
    if(hitPoints <= 0)
    {
        std::cout << name << " has no hit points left" << std::endl;
        return;
    }
    else
    {
        energyPoints--;
        std::cout << name << " attacks " << target << std::endl;
    }
    std::cout << name << " has " << energyPoints << " of energy points" << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if(hitPoints < 1)
    {
        std::cout << name << " died! No hit points left :("<<std::endl;
        return;
    }
    std::cout << name << " takes " << amount << " points of damage![Current hitPoints "<< hitPoints << "]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(energyPoints <= 0)
    {
        std::cout << name << " has no energy left" << std::endl;
        return;
    }
    if(hitPoints <= 0)
    {
        std::cout << name << " has no hit points left" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << name << " repair itself, regaining " << amount << " hit points! [Current hitPoints " << hitPoints << "]" << std::endl; 
}
