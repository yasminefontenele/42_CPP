/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:44:51 by yfontene          #+#    #+#             */
/*   Updated: 2025/01/31 12:20:32 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"

int main()
{
        try {
        // Teste 1: ShrubberyCreationForm
        std::cout << "=== Test: ShrubberyCreationForm ===" << std::endl;
        std::cout << "[testing file creation]" << std::endl;
        Bureaucrat Marvin("Marvin", 135);//higher than the grade to execute
        ShrubberyCreationForm shrubbery("Tree");
        std::cout << shrubbery << std::endl;

        Marvin.signForm(shrubbery);
        std::cout << shrubbery << std::endl;

        Marvin.executeForm(shrubbery);
        
        std::cout << std::endl;
        std::cout << "[testing exception]" << std::endl;
        Bureaucrat Yasmine("Yasmine", 138);//lower than the grade to execute
        ShrubberyCreationForm form_tree("home");
        std::cout << form_tree << std::endl;

        Yasmine.signForm(form_tree);
        std::cout << form_tree << std::endl;

        Yasmine.executeForm(form_tree);
        Yasmine.incrementGrade();
        Yasmine.executeForm(form_tree);

       // Teste 2: RobotomyRequestForm
        std::cout << "\n=== Test: RobotomyRequestForm ===" << std::endl;
        Bureaucrat alice("Alice", 50);
        RobotomyRequestForm robotomy("Target1");
        std::cout << robotomy << std::endl;

        alice.signForm(robotomy);
        alice.executeForm(robotomy);

        // Teste 3: PresidentialPardonForm
        std::cout << "\n=== Test: PresidentialPardonForm ===" << std::endl;
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Roosevelt");
        std::cout << pardon << std::endl;

        president.signForm(pardon);
        president.executeForm(pardon);

    } catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}