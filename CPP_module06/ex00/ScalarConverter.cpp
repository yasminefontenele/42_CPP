/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:49:33 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/17 19:54:15 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strtol: converts a string to a long int
strtof: converts a string to a float
strtod: converts a string to a double
+inff -inff nanf are valid float literals
+inf -inf nan are valid double literals
*/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *end;
    long val = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
        return true;
    return false;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal == "+inff" || literal == "-inff" || literal == "nanf")
        return true;
    char *end;
    float val = std::strtof(literal.c_str(), &end);
    return *end == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max();
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    if (literal == "+inf" || literal == "-inf" || literal == "nan")
        return true;
    char *end;
    double val = std::strtod(literal.c_str(), &end);
    if (val < -std::numeric_limits<double>::max() || val > std::numeric_limits<double>::max())
        return false;
    return *end == '\0';
}

void ScalarConverter::printChar(char c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
    {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
    else if (isInt(literal))
    {
        int i = std::atoi(literal.c_str());
        printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
    else if (isFloat(literal))
    {
        float f = std::strtof(literal.c_str(), NULL);
        printChar(static_cast<char>(f));
        printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
    }
    else if (isDouble(literal))
    {
        double d = std::strtod(literal.c_str(), NULL);
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
