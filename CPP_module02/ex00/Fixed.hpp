/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:33 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 11:05:16 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    
    public:
        Fixed();                  // Default constructor
        Fixed(const Fixed &other);// Copy constructor
        ~Fixed();                 // Destructor    
        
        //assignment operator
        Fixed &operator=(const Fixed &fixed);
        //method to return the raw value of the fixed point value
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif