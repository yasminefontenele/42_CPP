/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:38:26 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/13 18:48:07 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeSing;
        const int gradeExecute;
    
    protected:
        void checkExecution(const Bureaucrat &executor) const;

    public:
        AForm(const std::string &name, const int gradeSing, const int gradeExecute);
        virtual ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        
        
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeSing() const;
        int getGradeExecute() const;
    
        void beSigned(const Bureaucrat &b);

        virtual void execute(Bureaucrat const & executor) const = 0;

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
    class FormNotSignedException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &outputStream, const AForm &obj);

#endif