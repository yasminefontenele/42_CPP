/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:03:37 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 13:30:44 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Constructor default called in Brain" << std::endl;
    for(int i = 0; i < 100; i++)
        ideas[i] = "default idea";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Copy constructor called in Brain" << std::endl;
    *this = other;
}

Brain::~Brain()
{
    std::cout << "Destructor called in Brain" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Copy assignment called in Brain" << std::endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

const std::string &Brain::getIdeas(int i) const
{
    if(i >= 0 && i < 100)
        return(ideas[i]);
    throw std::out_of_range("Index out of bounds");
}

void Brain::setIdeas(int i, const std::string &idea)
{
    if(i >= 0 && i < 100)
        ideas[i] = idea;
    else
        throw std::out_of_range("Index out of bounds");
}