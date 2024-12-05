/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:08:09 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 12:00:39 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
// Default constructor
// Copy constructor
// Copy assignment operator
// Destructor
*/
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hitPoints;//ClapTrap health
        unsigned int energyPoints;//energy available for actions
        int attackDamage;
        
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);
        ~ClapTrap();
        
        void attack(const std::string& target);//Reduces 1 energy point and hit points to the target.
        void takeDamage(unsigned int amount);//Reduces hit points depending on the damage received.
        void beRepaired(unsigned int amount);//Consumes 1 energy point.Restores hit points to the given value.
};

#endif