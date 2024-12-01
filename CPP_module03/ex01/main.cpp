/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:44 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/01 19:38:06 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap ClapA("Maria");
    ClapA.attack("Joao");
    ClapA.takeDamage(3);
    ClapA.beRepaired(2);

    ScavTrap scav("Joao");
    scav.attack("target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();
    
    ScavTrap scavCopy(scav);
    ScavTrap scavAssign;
    scavAssign = scav;
}
