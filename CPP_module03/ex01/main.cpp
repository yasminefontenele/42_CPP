/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:44 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 12:05:47 by yfontene         ###   ########.fr       */
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

    ScavTrap scav("John");
    scav.attack("Mary");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    ScavTrap scavCopy(scav);
    ScavTrap scavAssign;
    scavAssign = scav;
}
