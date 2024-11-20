/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:33 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 18:14:55 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>//to roundf

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
        
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif