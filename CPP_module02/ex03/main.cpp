/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/25 19:09:24 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*COMO FAZER A CONEXAO DE BSP COM O MAIN*/

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