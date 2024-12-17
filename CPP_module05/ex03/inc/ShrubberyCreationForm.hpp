/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:08:03 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/13 18:09:51 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>//ofstream ifstream fstream 

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    
    public:
        ShrubberyCreationForm(const std::string &target);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

        void execute(Bureaucrat const & executor) const;
};
#endif