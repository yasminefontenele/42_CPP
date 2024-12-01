/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:48:45 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/01 19:36:59 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCARVTRAP_HPP
#define SCARVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);
        ~ScavTrap();

        ScavTrap &operator=(const ScavTrap &other);
        
        void attack(const std::string &target);
        void guardGate();
};

#endif