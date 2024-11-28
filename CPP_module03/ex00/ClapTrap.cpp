/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:08:12 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/28 18:42:21 by yfontene         ###   ########.fr       */
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
    attackDamage++;
    std::cout << name << " attacks " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if(hitPoints < 0)
        hitPoints = 0;
    std::cout << name << " takes " << amount << " points of damage!" << std::endl;
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
