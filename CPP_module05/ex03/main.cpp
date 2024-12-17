/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:44:51 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/17 16:41:56 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Intern.hpp"
#include "inc/Bureaucrat.hpp"

int main()
{
    try
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);

        AForm *form1 = intern.makeForm("shrubbery creation", "Home");
        AForm *form2 = intern.makeForm("robotomy request", "Marvin");
        AForm *form3 = intern.makeForm("presidential pardon", "Trump");
        
        if (form1)
        {
            boss.signForm(*form1);
            boss.executeForm(*form1);
            delete form1;
        }
        if (form2)
        {
            boss.signForm(*form2);
            boss.executeForm(*form2);
            delete form2;
        }
        if (form3)
        {
            boss.signForm(*form3);
            boss.executeForm(*form3);
            delete form3;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}