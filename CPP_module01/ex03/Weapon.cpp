/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:32:08 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 19:48:11 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {}

const std::string &Weapon::getType() const
{
    return (type);
}

void Weapon::setType(const std::string &newType)
{
    type = newType;
}