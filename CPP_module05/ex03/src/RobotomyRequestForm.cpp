/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:08:10 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/13 18:58:05 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::checkExecution(executor);
    std::srand(std::time(NULL));
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << target << " failed!" << std::endl;
}