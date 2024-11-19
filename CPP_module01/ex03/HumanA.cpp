/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:32:00 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 20:19:50 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//Constructor with initialization list to initialize the reference to the weapon and the name of the human
HumanA::HumanA(const std::string &name, Weapon &wepon) : name(name), weapon(wepon) {}

void HumanA::attack()
{
    std::cout << name << " attacks whit their " << weapon.getType() << std::endl;
}