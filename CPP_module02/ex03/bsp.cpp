/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:30:59 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/25 19:10:19 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
calculo triangulo em plano cartesiano
A(x1,y1), B(x2,y2), C(x3,y3)
Area = 1/2|x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
*/

Fixed calculateArea(Point const &a, Point const &b, Point const &c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) +
                  b.getX() * (c.getX() - a.getX()) +
                  c.getX() * (a.getY() - b.getX())) / 2;

    if(area < 0)
        return (area * -1);
    else
        return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed totalArea = calculateArea(a, b, c);
    Fixed area1 = calculateArea(p, b, c);
    Fixed area2 = calculateArea(a, p, c);
    Fixed area3 = calculateArea(a, b, p);

    if(totalArea = area1 + area2 + area3)
        return(true);
    else
        return(false);
    //return(totalArea = area1 + area2 + area3);    
}