/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:30:45 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 13:30:48 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string replace(std::string str, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return str;

	std::string result;
	std::size_t pos = 0;
	std::size_t found;

	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result += str.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}

	result += str.substr(pos);
	return result;
}


int main(int argc, char* argv[])
{
	std::ifstream	infile;
	std::stringstream buffer;

	if(argc != 4)
    	return (std::cout << "Wrong Amount of Arguments." << std::endl , 1);
	infile.open(argv[1]);
	if(infile.fail())
    	return (std::cout << "Wrong infile name." << std::endl , 1);
		
	buffer << infile.rdbuf();
	infile.close();

	std::fstream fs;
	std::string filename = std::string(argv[1]) + ".replace";

	fs.open (filename.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);
	if(fs.fail())
    	return (std::cout << "Fail to open replace file." << std::endl , 1);

	std::string bufferStr;
	
	bufferStr = replace(buffer.str(), argv[2], argv[3]);
	fs << bufferStr;

	fs.close();
	return 0;
}
