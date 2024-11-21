/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:33 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/21 18:51:25 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    
    public:
        Fixed();                  // Default constructor
        Fixed(const Fixed &other);// Copy constructor
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();                 // Destructor    
        
        //assignment operator
        Fixed &operator=(const Fixed &fixed);
        //method to return the raw value of the fixed point value
        int getRawBits(void) const;
        void setRawBits(int const raw);
        //convertion
        float toFloat(void) const;
        int toInt(void) const;
        
        //Comparison Operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        
        //Arithmetic operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        
        // Increment/decrement operators
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        //static methods
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif