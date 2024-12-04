/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:56:48 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/04 11:08:00 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(std::string const &name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &other)
{
    *this = other;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
    }
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i])
                delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx] = NULL;
} 

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}