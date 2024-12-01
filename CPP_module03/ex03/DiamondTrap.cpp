/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:38:02 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/01 19:51:05 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

/*
"Indirect non-virtual base class is not allowed"
DiamondTrap inherited from ScavTrap and FragTrap. Both ScavTrap and FragTrap inherited from ClapTrap.
This causes ClapTrap to be inherited twice in DiamondTrap, creating ambiguity.
This problem is known as diamond inheritance.
*/

DiamondTrap::DiamondTrap(): ClapTrap("DefaultClapTrapName"), name ("Default")
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), name(name)
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap constructor called for " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
        std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name
            << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
