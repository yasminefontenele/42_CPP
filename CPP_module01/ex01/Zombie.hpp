/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:46:13 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 18:40:10 by yfontene         ###   ########.fr       */
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
        Zombie();//constructor default
        Zombie(std::string name);//constructor with parameter
        ~Zombie();//destructor
        
        void announce( void );
        void setName(std::string name);
};

#endif


/********** default constructor **********
Is useful when we need to create objects without
complete information, but intend to configure them later.
Can initialize attributes with default values.*/

/********** parameter constructor **********
The is useful when we need to initialize the object
with complete information at creation time. We do not need to modify the
attributes after creating the object.
Can initializes attributes with user-supplied values.
*/