/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 16:45:05 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

/*int main()
{
    int nbrAnimals = 4;
    int i = 0;

    AAnimal *animals[nbrAnimals];

    while(i < nbrAnimals)
    {
        if(i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        i++;
    }

    i = 0;
    while(i < nbrAnimals)
    {
        delete animals[i];
        i++;
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Check deep copy of Dog class using copy constructor:" << std::endl;
    Dog *dog1 = new Dog;
    dog1->getBrain()->setIdeas(1, "Chase the ball!");
    Dog *dog2 = new Dog(*dog1);
    std::cout << "Dog1 Idea[0]: " << dog1->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2->getBrain()->getIdeas(0) << std::endl;
    delete dog1;
	std::cout << "Dog2 Idea[0]: " << dog2->getBrain()->getIdeas(0) << std::endl;
	delete dog2;
}*/


int main()
{
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();

    std::cout << j->getType() << " makes sound: ";
    j->makeSound();

    std::cout << i->getType() << " makes sound: ";
    i->makeSound();

    delete j;
    delete i;

    return 0;
}
