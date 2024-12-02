/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:54:02 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:59:32 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;    

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &other);

        virtual std::string getType() const;
        void makeSound() const;
};

#endif