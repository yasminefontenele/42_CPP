/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:35:32 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/20 10:03:09 by yfontene         ###   ########.fr       */
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
    std::ifstream infile(filename.c_str());//open the file. The c_str() converts the string to a const string
    if (!infile.is_open())//check if the file is open
        throw std::ios_base::failure("Unable to open the file");//throw an exception if the file is not open
    
    std::stringstream buffer;//create a string stream buffer
    buffer << infile.rdbuf();//read the file and store it in the buffer
    infile.close();//close the file
    return (buffer.str());//return the content of the file as a string
}

void FileProcessor::writeFile(const std::string &content) const
{
    std::string outputFilename = filename + ".replace";
    std::ofstream outfile(outputFilename.c_str());//open the file

    if(!outfile.is_open())
        throw std::ios_base::failure("Error: Unable to open the file");//throw an exception if the file is not open

    outfile << content;//write the content to the file
}

std::string FileProcessor::replaceString(const std::string &content) const
{
    if(s1.empty())
        return (content);
        
    std::string result;
    size_t start = 0;
    size_t pos = content.find(s1, start);//find the first occurrence of s1 in the content

    while (pos != std::string::npos)//while there is an occurrence of s1 in the content
    {
        result += content.substr(start, pos - start) + s2;//replace s1 with s2
        start = pos + s1.length();//update the start position
        pos = content.find(s1, start);//find the next occurrence of s1 in the content
    }
    
    result += content.substr(start);//add the remaining content to the result
    return (result);//return the updated content
}