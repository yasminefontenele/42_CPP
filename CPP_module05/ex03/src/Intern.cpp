/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:24:39 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/17 16:20:30 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm *createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    //array of pointers to functions
    AForm *(*formCreators[])(const std::string &target) = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };
    
    for (int i = 0; i < 3; ++i)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Error: Form " << formName << " does not exist." << std::endl;
    return NULL;
}

/*
solution for C++11
lambda function:
[capture] (parameters) -> return_type { body }

[capture]: Defines which variables in the outer scope the lambda function can access.
Options include capturing by value (=) or by reference (&).
(parameters): Lists the parameters that the lambda function receives, just like a normal function.
-> return_type: Specifies the data type that the lambda function returns.
If the return type can be deduced by the compiler, this part can be omitted.
{ body }: Contains the code that the lambda function executes.
*/