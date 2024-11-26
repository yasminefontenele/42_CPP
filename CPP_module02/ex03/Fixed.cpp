/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/26 11:39:40 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed() : fixedPointValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    //std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value *(1 << fractionalBits));
}


Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}


Fixed &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPointValue = other.fixedPointValue;
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
    return (fixedPointValue >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return (out);
}

/* Comparison Operators */
bool Fixed::operator>(const Fixed &other) const
{
    return (this->fixedPointValue > other.fixedPointValue);
}


bool Fixed::operator<(const Fixed &other) const
{
    return (this->fixedPointValue < other.fixedPointValue);
}


bool Fixed::operator>=(const Fixed &other) const
{
    return (this->fixedPointValue >= other.fixedPointValue);
}


bool Fixed::operator<=(const Fixed &other) const
{
    return (this->fixedPointValue <= other.fixedPointValue);
}


bool Fixed::operator==(const Fixed &other) const
{
    return (this->fixedPointValue == other.fixedPointValue);
}


bool Fixed::operator!=(const Fixed &other) const
{
    return (this->fixedPointValue != other.fixedPointValue);
}

/* Arithmetic Operators */
Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.fixedPointValue == 0)
    {
        std::cerr << "ERROR: Division by 0 is not possible" << std::endl;
        exit(1);
    }
    return (Fixed(this->toFloat() / other.toFloat()));
}

/* Increment/Decrement Operators */
Fixed &Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

/* Static min and max methods */
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
   return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}
