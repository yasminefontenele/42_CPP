/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:57:24 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 18:28:37 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}//default constructor

Zombie::Zombie(std::string name) : name(name) {}//parameter constructor

Zombie::~Zombie()//destructor
{
    std::cout << name << ": is destroyed!" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;//this->name is the attribute name of the class
}