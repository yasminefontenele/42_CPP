/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:25 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 16:40:05 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP 

#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
    AAnimal();
    AAnimal(const AAnimal &other);
    virtual ~AAnimal();

    AAnimal &operator=(const AAnimal &other);

    virtual void makeSound() const = 0;
    virtual std::string getType() const;
};

#endif