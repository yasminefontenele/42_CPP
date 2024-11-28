/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:44 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/28 18:48:09 by yfontene         ###   ########.fr       */
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

    ClapTrap ClapC = ClapA;
    ClapC.attack("Another target");
    
    ClapTrap ClapD;
    ClapD = ClapB;
}