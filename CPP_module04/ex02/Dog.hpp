/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:32:45 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 16:35:04 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(const Dog &other);
        ~Dog();

        Dog &operator=(const Dog &other);

        void makeSound() const;
        std::string getType() const;
        Brain *getBrain() const;     
};

#endif