/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:25 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:45:42 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP 

#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
    Animal();
    Animal(const Animal &other);
    virtual ~Animal();

    Animal &operator=(const Animal &other);

    virtual std::string getType() const;
    virtual void makeSound() const;
};

#endif