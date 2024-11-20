/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 15:42:43 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

//My main
/*int main()
{
    //create a weapon
    Weapon club("crude spiked club");

    //create a humanA always with weapon
    HumanA bob("Bob", club);
    bob.attack();

    //change the weapon
    club.setType("some other type of club");
    bob.attack();

    //HumanB could or could not have a weapon
    HumanB jim("Jim");
    jim.attack();//no weapon
    jim.setWeapon(club);
    jim.attack();

    return (0);
}*/

//PDF
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
