/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:44 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 11:56:26 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap ClapA("Maria");
    ClapTrap ClapB("Joao");

    ClapA.attack("Joao");
    ClapB.takeDamage(3);
    ClapB.beRepaired(2);

    ClapB.attack("Maria");
    ClapA.takeDamage(6);
    ClapA.beRepaired(8);

    ClapA.attack("Joao");
    ClapB.takeDamage(6);
    ClapB.beRepaired(2);
    ClapA.attack("Joao");
    ClapB.takeDamage(5);

    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    ClapTrap ClapC = ClapA;
    ClapC.attack("Another target");
    
    ClapTrap ClapD;
    ClapD = ClapB;

    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << std::endl;

    ClapTrap ClapE("John");
    ClapTrap ClapF(ClapE);
    
}



