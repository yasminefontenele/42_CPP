/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:43:15 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 10:13:48 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
        
    public:
        Cat();
        Cat(const Cat &other);
        virtual ~Cat();
        Cat &operator=(const Cat &other);
        
        void makeSound() const;
        std::string getType() const;
        Brain *getBrain() const;
};

#endif