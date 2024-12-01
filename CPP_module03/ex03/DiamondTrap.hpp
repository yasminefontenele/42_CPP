/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:38:07 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/01 19:39:16 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();

        DiamondTrap& operator=(const DiamondTrap& other);

        void whoAmI();
};

#endif 

/*
             ClapTrap
                |
       +--------+--------+
       |                 |
   ScavTrap          FragTrap
        \               /
         \             /
          \           /
           DiamondTrap


ClapTrap (Classe Base)
  |
  --> ScavTrap (Derivada de ClapTrap)
  |
  --> FragTrap (Derivada de ClapTrap)
  |
  --> DiamondTrap (Derivada de ScavTrap e FragTrap)
*/