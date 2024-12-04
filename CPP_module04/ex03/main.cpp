/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/04 11:32:30 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Character.hpp"
#include "inc/MateriaSource.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"
#include "inc/ICharacter.hpp"
#include "inc/IMateriaSource.hpp"
#include "inc/AMateria.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
