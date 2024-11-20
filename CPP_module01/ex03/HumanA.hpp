/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:32:02 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 20:04:32 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
    private:
        std::string name;//name of the human
        Weapon &weapon;//reference to the weapon(always present)
    public:
        HumanA(const std::string &name, Weapon &weapon);//constructor
        void attack();
};

#endif