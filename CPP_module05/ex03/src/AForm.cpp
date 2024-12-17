/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:38:39 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/13 18:57:51 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(const std::string &name, const int gradeSing, const int gradeExecute) : name(name), isSigned(false), gradeSing(gradeSing), gradeExecute(gradeExecute)
{
    if(gradeSing < 1 || gradeExecute < 1) throw GradeTooHighException();
    if(gradeSing > 150 || gradeExecute > 150) throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : name(other.name), gradeSing(other.gradeSing), gradeExecute(other.gradeExecute) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this; 
}

std::string const AForm::getName() const
{
    return name;
}

int AForm::getGradeSing() const
{
    return gradeSing;
}

int AForm::getGradeExecute() const
{
    return gradeExecute;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() > gradeSing)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low!";
}

std::ostream &operator<<(std::ostream &outputStream, const AForm &obj)
{
    outputStream << "AForm " << obj.getName() << ", requires grade "
    << obj.getGradeSing() << " to sign, grade " << obj.getGradeExecute()
    << " to execute, signed: " << (obj.getIsSigned() ? "yes" : "no");
    return outputStream;
}

void AForm::checkExecution(const Bureaucrat &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeExecute)
        throw GradeTooLowException();
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}
