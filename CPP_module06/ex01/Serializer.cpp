/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:46:00 by yfontene          #+#    #+#             */
/*   Updated: 2025/01/06 14:28:50 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other)
{
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

uintptr_t Serializer::serializer(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserializer(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

const char *Serializer::SerializationException::what() const throw()
{
	return "Invalid pointer";
}