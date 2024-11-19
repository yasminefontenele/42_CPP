/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:31:57 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 20:24:54 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &wepon)
{
    this->weapon = &wepon;//pq this-> ?
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks whith their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}