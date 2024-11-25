/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:31:09 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/25 18:35:18 by yfontene         ###   ########.fr       */
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
        Point();//constroctor
        Point(const Fixed x, const Fixed y);//construtor de valores
        Point(const Point &other);//contrutor de copia
        ~Point();
        
        Point &operator=(const Point &other);//operador de atribuicao
        
        Fixed getX() const;
        Fixed getY() const;       
};

#endif