/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/05 18:41:57 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "Tests from subject:" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "My tests:" << std::endl;
    int nbr = 4;
    const Animal *animals[nbr];
    std::cout << "Creating the animals:" << std::endl;
    for(int y = 0; y < nbr; y++)
    {
        if(y % 2 == 0)
            animals[y] = new Dog();
        else
            animals[y] = new Cat();
    }
    std::cout << "Deleting the animals:" << std::endl;
    for (int y = 0; y < nbr; y++)
        delete animals[y];

    std::cout << std::endl;

    // tests the deep copy
    std::cout << "Testing the deep copy:" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdeas(1, "Chase the ball!");
    Dog dog2 = dog1;

    std::cout << "Dog1 Idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;
    
    std::cout << std::endl;
    std::cout << "Testing the change of idea:" << std::endl;
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