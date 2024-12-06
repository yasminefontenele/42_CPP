/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:56:48 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 12:35:42 by yfontene         ###   ########.fr       */
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
        {
            std::cout << "[" << this->name << "] unequips " << inventory[i]->getType() << " from slot " << i << std::endl;
            delete inventory[i];
            inventory[i] = NULL;
        }

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
        if (inventory[i] == m)
        {
            std::cout << "[" << this->name << "] already has " << m->getType() << " equipped." << std::endl;
            return;
        }
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << "[" << this->name << "] equips " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "[" << this->name << "] can't equips " << m->getType() << " the inventory is full!!" << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4)
    {
            std::cout << "[" << this->name << "] unequips " << inventory[idx]->getType() << " from slot " << idx << std::endl;
            inventory[idx] = NULL;
    }
    std::cout << "[" << this->name << "] can't unequip slot " << idx << " (invalid or empty)" << std::endl; 
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}

// for testing purposes
void Character::printInventory() const
{
    std::cout << "[" << this->name << "] Inventory:" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "  Slot " << i << ": ";
        if (this->inventory[i])
            std::cout << this->inventory[i]->getType() << std::endl;
        else
            std::cout << "Empty" << std::endl;
    }
    std::cout << std::endl;
}