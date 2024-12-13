/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:44:51 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/13 17:42:54 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try 
    {
        Bureaucrat bob("Bob", 2);
        Form formA("FormA", 5, 10);
        Form formB("FormB", 1, 1);

        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.signForm(formA);
        std::cout << formA << std::endl;

        bob.signForm(formB); // Should fail
        std::cout << formB << std::endl;

        bob.incrementGrade(); // Promote Bob to grade 1
        bob.signForm(formB); // Should now succeed
        std::cout << formB << std::endl;

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}