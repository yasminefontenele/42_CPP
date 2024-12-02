/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:16:28 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 13:54:14 by yfontene         ###   ########.fr       */
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
    std::cout << "Testing the creation and delete of animals:" << std::endl;
    const Animal *animals[4];
    //creating half Dog and half Cat
    for (int y = 0; y < 2; ++y)
        animals[y] = new Dog();
    for (int y = 2; y < 4; ++y)
        animals[y] = new Cat();

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << std::endl;

    // tests the deep copy
    std::cout << "Testing the deep copy:" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdeas(0, "Chase the ball!");
    Dog dog2 = dog1;

    std::cout << "Dog1 Idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Testing the change of idea:" << std::endl;
    dog2.getBrain()->setIdeas(0, "Guard the house!");
    std::cout << "Dog1 Idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Dog2 Idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;

    return 0;
}