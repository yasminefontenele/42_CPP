/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:38:26 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/12 15:49:43 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSing;
        const int gradeExecute;

    public:
        Form(const std::string &name, bool isSigned, const int gradeSing, const int gradeExecute);
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeSing() const;
        int getGradeExecute() const;
    
        void beSigned(Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &outputStream, const Form &obj);

#endif