/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:25 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 10:23:31 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP 

#include <iostream>
#include <string>

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

/*If the destructor is not virtual, only the base class destructor will be called when deleting
a derived object, which can lead to memory leaks or undefined behavior if the derived class allocates
resources (such as dynamic memory).*/