/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:31:06 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/26 13:52:45 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}