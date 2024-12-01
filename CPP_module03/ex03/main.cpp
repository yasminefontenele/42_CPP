/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:44 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/01 20:08:51 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

void printSection(const std::string &title)
{
    std::cout << "\033[1m" << title << "\033[0m\n";
}

int main()
{
    printSection("Constructor:");
    DiamondTrap diamond("Yasmine");
    std::cout << std::endl;
    printSection("Instance Methods:");
    diamond.attack("Marvin");
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();
    
    std::cout << std::endl;
    printSection("Copying, attribution and destruction:");
    DiamondTrap copy(diamond);
    DiamondTrap assign;
    assign = diamond;
}