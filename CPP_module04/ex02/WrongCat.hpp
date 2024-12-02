/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:54:02 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 12:57:54 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    protected:
        std::string type;    

    public:
        WrongCat();
        WrongCat(const WrongCat &other);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &other);

        void makeSound() const;
        std::string getType() const;
};

#endif