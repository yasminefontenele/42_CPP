/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 18:20:59 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;//multipleis for the factor of the scale
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value *(1 << fractionalBits));
}

//copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;//reusing the assignment operator to avoid code duplication
}

//destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)//check for self-assignment to avoid deleting the object before copying it(checks if the object on the left (this) is not the same object on the right)
        this->fixedPointValue = other.fixedPointValue;//copy the value from the right object to the left object
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat() const
{
    return (static_cast<float>(fixedPointValue) / (1 << fractionalBits));
}

int Fixed::toInt() const
{
    return (fixedPointValue >> fractionalBits);//Divide by scale factor
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();//Displays the floating point representation
    return (out);
}