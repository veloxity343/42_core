/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:15:01 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/02 11:33:57 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

std::string ft_replace(const std::string& buffer, const std::string& search, const std::string& replace)
{
	if (search.empty())
	{
		std::cerr << "Error: Search string cannot be empty." << std::endl;
		return (buffer);
    }
	std::string result = buffer;
	size_t pos = 0;
	while ((pos = result.find(search, pos)) != std::string::npos)
	{
		result.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return (result);
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <file_name> <search> <replace>" << std::endl;
		return (EXIT_FAILURE);
	}
	const std::string filename = argv[1];
	const std::string search = argv[2];
	const std::string replace = argv[3];
	const std::string outfile_name = filename + ".replace";
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::perror("Error opening input file");
		return (EXIT_FAILURE);
	}
	std::ofstream outfile(outfile_name.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile)
	{
		std::perror("Error creating output file");
		return (EXIT_FAILURE);
	}
	std::string buffer;
	while (std::getline(infile, buffer))
	{
		outfile << ft_replace(buffer, search, replace);
		if (infile.peek() != EOF)
			outfile << std::endl;
	}
	std::cout << "\033[1;32mReplacement complete. Output file:\t\033[0m" << outfile_name << std::endl;
	return (EXIT_SUCCESS);
}
