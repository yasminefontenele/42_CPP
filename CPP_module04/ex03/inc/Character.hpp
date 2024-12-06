/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:56:53 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 12:33:13 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventory[4];

    public:
        Character(std::string const &name);
        Character(const Character &other);
        ~Character();

        Character &operator=(const Character &other);

        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);

        void printInventory() const;// for testing purposes
};

#endif
