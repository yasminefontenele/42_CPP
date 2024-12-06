/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 10:47:12 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void printSection(const std::string &title)
{
    std::cout << "\033[1m" << title << "\033[0m\n";
}

int main()
{
    int nbrAnimals = 4;
    int i = 0;

    AAnimal *animals[nbrAnimals];

    printSection("Tests from subject:");
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

    std::cout << std::endl;
    printSection("Check deep copy of Dog with diferent ideas:");
    Dog *dog1 = new Dog;
    dog1->getBrain()->setIdeas(1, "Chase the ball!");
    Dog *dog2 = new Dog(*dog1);
    dog2->getBrain()->setIdeas(1, "pretend to be dead!");
    std::cout << std::endl;
    std::cout << "Dog1 Idea[0]: " << dog1->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog1 Idea[1]: " << dog1->getBrain()->getIdeas(1) << std::endl;
    std::cout << "Dog2 Idea[1]: " << dog2->getBrain()->getIdeas(1) << std::endl;
    std::cout << std::endl;
    delete dog1;
	delete dog2;

    return 0;
}
