/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/26 13:56:20 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const &a, Point const &b, Point const &c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    Point pointInside(5, 5);
    Point pointOutside(15, 5);

    Point pointOnEdge(5, 0);
    Point pointOnVertex(0, 0);

    std::cout << "Point inside: " << bsp(a, b, c, pointInside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, pointOutside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, pointOnEdge) << std::endl;
    std::cout << "Point on vertex: " << bsp(a, b, c, pointOnVertex) << std::endl;

    return 0;
}