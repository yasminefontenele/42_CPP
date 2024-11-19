/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/18 19:27:17 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    //pointer to string
    std::string *stringPTR = &brain;
    //reference to string
    std::string &stringREF = brain;

    std::cout << "Memory address of string variable: " << &brain << std::endl;
    std::cout << "Memory adress held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory adress held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl; 

    return (0);   
}