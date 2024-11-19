/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:32:05 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 20:22:37 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
    private:
        std::string name;//name of the human
        Weapon *weapon;//pointer to the weapon (can be null)
    public:
        HumanB(const std::string &name);
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif