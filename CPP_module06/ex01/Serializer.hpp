/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:46:09 by yfontene          #+#    #+#             */
/*   Updated: 2025/01/06 14:27:58 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <stdint.h>

#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        
    public:
        static uintptr_t serializer(Data *ptr);//Serialize the Data struct into a uintptr_t
        static Data *deserializer(uintptr_t raw);

    class SerializationException: public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif