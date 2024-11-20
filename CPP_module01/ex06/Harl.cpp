/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:14:25 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 10:48:36 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*Private methods that display the messages for each level*/
void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*Public method that calls the private methods based on the level*/
void Harl::complain( std::string level )
{
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*actions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int levelIndex = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex)
    {
        case 0:
            (this->*actions[0])();
            (this->*actions[1])();
            (this->*actions[2])();
            (this->*actions[3])();
            break;
        case 1:
            (this->*actions[1])();
            (this->*actions[2])();
            (this->*actions[3])();
            break;
        case 2:
            (this->*actions[2])();
            (this->*actions[3])();
            break;
        case 3:
            (this->*actions[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}