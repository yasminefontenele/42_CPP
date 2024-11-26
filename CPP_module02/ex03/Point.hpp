/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:31:09 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/26 13:51:08 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        
        Fixed getX() const;
        Fixed getY() const;       
};

#endif