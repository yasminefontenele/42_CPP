/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/06 10:17:58 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void printSection(const std::string &title)
{
    std::cout << "\033[1m" << title << "\033[0m\n";
}

int main()
{
    printSection("Tests from subject:");
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << std::endl;
    printSection("My tests:");
    int nbr = 4;
    const Animal *animals[nbr];
    printSection("Creating the animals:");
    for(int y = 0; y < nbr; y++)
    {
        if(y % 2 == 0)
            animals[y] = new Dog();
        else
            animals[y] = new Cat();
    }
    printSection("Deleting the animals:");
    for (int y = 0; y < nbr; y++)
        delete animals[y];

    std::cout << std::endl;

    // tests the deep copy
    printSection("Deep copy tests:");
    Dog dog1;
    dog1.getBrain()->setIdeas(1, "Chase the ball!");
    Dog dog2 = dog1;

    std::cout << "Dog1 Idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;
    
    std::cout << std::endl;
    printSection("Changing the idea:");
    std::cout << "Dog1 Idea[0]: " << dog1.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;
    std::cout << std::endl;
    dog2.getBrain()->setIdeas(2, "Guard the house!");
    dog2.getBrain()->setIdeas(3, "pretend to be dead");
    
    std::cout << "Dog1 Idea[0]: " << dog1.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2.getBrain()->getIdeas(1) << std::endl;
    std::cout << "Dog2 Idea[1]: " << dog2.getBrain()->getIdeas(2) << std::endl;
    std::cout << "Dog2 Idea[2]: " << dog2.getBrain()->getIdeas(3) << std::endl;
    std::cout << std::endl;
    
    return 0;
}