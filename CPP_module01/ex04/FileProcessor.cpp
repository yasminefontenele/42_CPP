/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:35:32 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/19 14:51:20 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileProcessor.hpp"

//read the content of the file and return it as a string
//constroctor
FileProcessor::FileProcessor(const std::string &filename, const std::string &s1,
const std::string &s2) : filename(filename), s1(s1), s2(s2){}

//method
void FileProcessor::processFile() const
{
    std::string content = readFile();//read the content of the file
    std::string updatedContent = replaceString(content);//replace the string
    writeFile(updatedContent);//write the updated content to the file
}

std::string FileProcessor::readFile() const
{
    std::ifstream file(filename);//open the file
}