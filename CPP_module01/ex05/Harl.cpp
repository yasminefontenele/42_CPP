/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:14:25 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 10:35:18 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*Private methods that display the messages for each level*/
void Harl::debug()
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO] I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING] I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*Public method that calls the private methods based on the level*/
void Harl::complain( std::string level )
{
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*actions[i])();//Call the method using the pointer to the method
            return;
        }
    }

    //If the level is not found
    std::cout << "Unknown level: Harl doesn't understand this level of complaint." << std::endl;
}