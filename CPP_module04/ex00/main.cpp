/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 13:45:01 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;
    
    std::cout << i->getType() << " makes sound: ";
    i->makeSound();
    std::cout << j->getType() << " makes sound: ";
    j->makeSound();
    std::cout << meta->getType() << " makes sound: ";
    meta->makeSound();

    std::cout << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << wrongAnimal->getType() << " makes sound: ";
    wrongAnimal->makeSound();
    std::cout << wrongCat->getType() << " makes sound: ";
    wrongCat->makeSound();

    std::cout << std::endl;
    delete i;
	delete j;
	delete meta;
    delete wrongAnimal;
    delete wrongCat;
    
    return 0; 
}

/*
I can't use:
    delete meta;
    delete j;
    delete i;
When a class has virtual methods, it is polymorphic.
If I delete a polymorphic object via a pointer to the base class,
the behavior is undefined unless the base class destructor is virtual.

This is because the virtual destructor ensures that destructors of
derived classes are called correctly.
So I had to change the destructor from Animal to virtual
*/