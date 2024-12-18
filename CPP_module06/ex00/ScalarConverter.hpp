/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:49:41 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/18 18:14:12 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);

        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);

        static void printChar(char c);
        static void printInt(int i);
        static void printFloat(float f);
        static void printDouble(double d);
        
    public:
        static void convert(const std::string &literal);
};

#endif

/*
The things in this class is private and static.
It acts purely as a utility tool, i.e.
all relevant functionality must be accessed statically.
The convert method is the only function the user needs
to call to perform the conversion.

The class constructor is private, which prevents the creation
of ScalarConverter objects. This reinforces the "static class" design.
*/