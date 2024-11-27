/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/27 16:20:35 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}
/* in fractionalBits the left shift operator (<<) shifts the bits of a number to
the left. For each offset, it's like multiplying the number by 2.
e.g.:
If fractionalBits = 8, then the offset is equivalent to multiplying by 2^8=256.
Like this:
fixedPointValue = 5 << 8; same as 5 * 256(2^8) = 1280
[This means that fixedPointValue will store 1280, which corresponds to the decimal value 5.0 in the fixed point system.]
fixedPointValue = 3 << 1; same as 3 * 2(2^1) = 6
fixedPointValue = 3 << 2; same as 3 * 4(2^2) = 12
*/
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;//multipleis for the factor of the scale
}

/*
The roundf function (from <cmath>) rounds a floating point number to the nearest integer.
E.g.:
If value = 42.42 e fractionalBits = 8:
fixedPointValue = roundf (42.42×256) = roundf(10883.52) =10884
*/
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
    if (this != &other)//checks if the object on the left (this) is not the same object on the right
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

/*converts the stored fixed-point value to a floating-point number.
[static_cast<float>] The fixedPointValue is an int, to perform division
correctly and obtain a decimal number, we need to convert it to a floating point number.
[1 << fractionalBits] The value stored in fixedPointValue was scaled up at the time it
was converted to fixed point. To reverse the scale and recover the original decimal number,
we divide by the same scale factor.
E.g.:
If fixedPointValue = 10884 and fractionalBits = 8
float result = static_cast<float>(fixedPointValue) / (1 << fractionalBits);
result = 10884/256 =42.421875
*/
float Fixed::toFloat() const
{
    return (static_cast<float>(fixedPointValue) / (1 << fractionalBits));
}

/*
[>> fractionalBits] The right shift operator (>>) shifts the bits of a number to the
right. For each offset, it's like dividing the number by 2 (no decimals, as it's an integer).
E.g.:
8 >> 1 = 4 same as 8 / (2^1) = 4
8 >> 2 =2 same as 8 / (2^2) = 2
result = fixedPointValue(10884) >> fractionalBits(8);
result = 10884 >> 8 = 10884/256 = 42
*/
int Fixed::toInt() const
{
    return (fixedPointValue >> fractionalBits);//Divide by scale factor
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();//Displays the floating point representation
    return (out);
}

/*
  Summary:
    << and >>: Bitwise operations that perform multiplication and division by powers of 2, used to manipulate fixed-point values.
    roundf: Ensures that floating point values ​​are rounded before being stored as fixed point.
    static_cast: Converts values ​​to float to perform accurate divisions.
    operator<<: Overload to display the floating point representation of the stored value.
*/