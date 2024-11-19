/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:20 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 18:41:44 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);

    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].setName(name);

    return (horde);//return the address of the first element of the array
}