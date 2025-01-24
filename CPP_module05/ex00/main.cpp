/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:44:51 by yfontene          #+#    #+#             */
/*   Updated: 2025/01/24 11:31:51 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Yasmine", 1);
        Bureaucrat b2("Marvin", 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        b1.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Joao", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat b4("Maria", 50);
        b4.decrementGrade();
        std::cout << b4 << std::endl;
        b4.incrementGrade();
        std::cout << b4 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}