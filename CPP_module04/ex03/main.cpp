/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 14:07:23 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Character.hpp"
#include "inc/MateriaSource.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"
#include "inc/ICharacter.hpp"
#include "inc/IMateriaSource.hpp"
#include "inc/AMateria.hpp"
#include <iomanip>


/*void printSection(const std::string &title)
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "\033[1m" << title << "\033[0m\n";
    std::cout << "---------------------------------------------" << std::endl;
}*/

#include <iostream>
#include <iomanip>

void printSection(const std::string& title)
{
    int totalWidth = 60;
    int titleWidth = title.length();

    int filling = (totalWidth - titleWidth) / 2;
    int extraFilling = (totalWidth - titleWidth) % 2;

    std::cout << std::string(totalWidth, '-') << std::endl;

    std::cout << std::string(filling, ' ')
              << "\033[1m" << title << "\033[0m"
              << std::string(filling + extraFilling, ' ')
              << std::endl;

    std::cout << std::string(totalWidth, '-') << std::endl;
}

static void printPersonage(std::string const &name)
{
    std::cout << "[" << name << "]" << std::endl;
}

static void testSubject(void)
{
	printSection("SUBJECT");
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("unknown");
    std::cout << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

    std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
}

static void	testingICharacter(void)
{
	printSection("CHARACTER");
	ICharacter	*Dumbledore = new Character("Marvin");
	ICharacter	*Gandalf = new Character("Yasmine");
	AMateria	*ice = new Ice();

    std::cout << std::endl;
    std::cout << "Before equipping..." << std::endl;

    Dumbledore->equip(new Ice());
    Dumbledore->equip(ice);
    Dumbledore->equip(new Cure);
    Gandalf->equip(new Ice());
    Gandalf->equip(new Cure);
    Gandalf->equip(new Cure);
    Gandalf->equip(new Ice());
    Gandalf->equip(new Ice());

    std::cout << std::endl;
    std::cout << "After equipping..." << std::endl;

	Dumbledore->printInventory();
	Gandalf->printInventory();

    std::cout << std::endl;
    printPersonage(Dumbledore->getName());
	Dumbledore->use(0, *Gandalf);
	Dumbledore->use(1, *Gandalf);
	Dumbledore->use(3, *Gandalf);
    printPersonage(Gandalf->getName());
	Gandalf->use(2, *Dumbledore);

	Dumbledore->unequip(1);
	Dumbledore->printInventory();
	Dumbledore->use(1, *Gandalf);

	Dumbledore->equip(new Cure());
	Dumbledore->printInventory();
	Dumbledore->use(1, *Gandalf);

	delete Dumbledore;
	delete Gandalf;
	delete ice;
}

static void	testingMateriaSource()
{
	printSection("MATERIA SOURCE");
	IMateriaSource	*matSource = new MateriaSource();
    ICharacter *Dumbledore = new Character("Marvin");
    ICharacter *Gandalf = new Character("Yasmine");
	
	matSource->learnMateria(new Ice());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());
	matSource->learnMateria(new Cure());

	Dumbledore->printInventory();
    
	Dumbledore->equip(matSource->createMateria("ice"));
	Dumbledore->equip(matSource->createMateria("cure"));
	Dumbledore->equip(matSource->createMateria("cure"));
	Dumbledore->equip(matSource->createMateria("ice"));
	Dumbledore->printInventory();
	Dumbledore->equip(matSource->createMateria("cure"));
	Dumbledore->printInventory();

	Dumbledore->use(0, *Gandalf);
	Dumbledore->use(2, *Gandalf);

    std::cout << std::endl;
	delete matSource;
	delete Dumbledore;
	delete Gandalf;
}

int main()
{
    testSubject();
    std::cout << std::endl;
    testingICharacter();
    std::cout << std::endl;
    testingMateriaSource();
    
    return 0;
}
