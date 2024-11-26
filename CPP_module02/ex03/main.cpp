/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/26 11:34:38 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const &a, Point const &b, Point const &c);
bool bsp(Point const &a, Point const &b, Point const &c, Point const &p);

int main()
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(0));
    Point c(Fixed(5), Fixed(10));

    Point pointInside(Fixed(5), Fixed(5));
    Point pointOutside(Fixed(15), Fixed(5));

    std::cout << "Point inside: " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, pointOutside) << std::endl;

    return 0;
}