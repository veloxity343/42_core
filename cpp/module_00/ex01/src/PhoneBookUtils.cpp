/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:09 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 11:29:29 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookUtils.hpp"

void	display_welcome(void)
{
	system("clear");
	std::cout << "Welcome to PhoneBook" << std::endl;
	wait_for_enter();
}

void	display_menu_and_prompt(std::string &input)
{
	std::cout << "+------------MAIN MENU------------+" << std::endl;
	std::cout << "| ADD: to add a new contact       |" << std::endl;
	std::cout << "| SEARCH: to search for a contact |" << std::endl;
	std::cout << "| EXIT: to exit the phonebook     |" << std::endl;
	std::cout << "+---------------------------------+" << std::endl;
	std::cout << "Enter your command (ADD, SEARCH, EXIT): ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	input = trim_whitespace(input);
}

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	else
		return(str);
}

std::string	trim_whitespace(std::string str)
{
	std::string	whitespace	= " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(whitespace);
	end = str.find_last_not_of(whitespace);
	if (start == std::string::npos || end == std::string::npos)
		return ("");
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

void	get_input(std::string prompt, std::string &str)
{
	std::cout << prompt;
	std::getline(std::cin, str);
	if (std::cin.eof())
		exit(0);
	str = trim_whitespace(str);
}

void	wait_for_enter(void)
{
	std::cout << "Press Enter to continue..." << std::endl;
	while (1)
	{
		if (std::cin.get() == '\n')
			break ;
		else if (std::cin.eof())
		{
			system("clear");
			exit(0);
		}
	}
	system("clear");
}
