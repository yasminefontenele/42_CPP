/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:38:39 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/13 17:46:10 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, const int gradeSing, const int gradeExecute) : name(name), isSigned(false), gradeSing(gradeSing), gradeExecute(gradeExecute)
{
    if(gradeSing < 1 || gradeExecute < 1) throw GradeTooHighException();
    if(gradeSing > 150 || gradeExecute > 150) throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : name(other.name), gradeSing(other.gradeSing), gradeExecute(other.gradeExecute) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this; 
}

std::string Form::getName() const
{
    return name;
}

int Form::getGradeSing() const
{
    return gradeSing;
}

int Form::getGradeExecute() const
{
    return gradeExecute;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

void Form::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() > gradeSing)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &outputStream, const Form &obj)
{
    outputStream << "Form " << obj.getName() << ", requires grade "
    << obj.getGradeSing() << " to sign, grade " << obj.getGradeExecute()
    << " to execute, signed: " << (obj.getIsSigned() ? "yes" : "no");
    return outputStream;
}
