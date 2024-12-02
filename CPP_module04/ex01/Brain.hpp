/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:03:34 by yfontene          #+#    #+#             */
/*   Updated: 2024/12/02 13:30:47 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &other);
        ~Brain();
        Brain &operator=(const Brain &other);
        
        const std::string &getIdeas(int i) const;
        void setIdeas(int i, const std::string &idea);
};

#endif