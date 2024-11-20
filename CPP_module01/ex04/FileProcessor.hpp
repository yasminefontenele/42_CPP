/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:35:27 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 09:45:51 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEPROCESSOR_HPP
#define FILEPROCESSOR_HPP

#include <fstream>//file stream library to read and write files
#include <sstream>//string stream library to manipulate strings
#include <iostream>
#include <stdexcept>//exception library to throw exceptions in case of errors

class FileProcessor
{
    private:
        //attributes
        std::string filename;
        std::string s1;
        std::string s2;
        //methods
        std::string readFile() const;
        void writeFile(const std::string &content) const;
        std::string replaceString(const std::string &content) const;

    public:
        FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2);
        void processFile() const;
};

#endif