/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:36 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 10:09:30 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: Please, digit " << av[0] << " <filename> <originalstring> <replacedstring>" << std::endl;
        return (1);
    }
    try
    {
        FileProcessor processor(av[1], av[2], av[3]);
        processor.processFile();
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;//e.what returns the error message of the exception thrown
        return (1);
    }
    return (0);
}