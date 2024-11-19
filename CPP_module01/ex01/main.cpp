/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 18:42:18 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    std::string name = "Zombie";

    Zombie *horde = zombieHorde(N, name);
    if (!horde)
    {
        std::cout << "Error: failed to create the horde!" << std::endl;
        return (1);
    }
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete [] horde;

    return (0);
}