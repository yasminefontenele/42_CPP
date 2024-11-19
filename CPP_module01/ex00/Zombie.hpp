/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:13 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 16:57:18 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>//std::string
#include <iostream>//std::cout

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string name);//constructor
        ~Zombie();//destructor
        
        void announce( void );
};

#endif