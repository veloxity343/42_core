/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:02 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 17:12:30 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <unistd.h>
#include <cctype>
#include <algorithm>

int	main(void)
{
	std::string	input;
	PhoneBook phonebook;

	while (1)
	{
		system("clear");
		display_menu_and_prompt(input);
		if (input.empty())
			continue ;
		for (std::string::size_type i = 0; i < input.length(); ++i)
            input[i] = std::toupper(static_cast<unsigned char>(input[i]));
		if (input == "EXIT")
			return (system("clear"), 0);
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
		{
			std::cout << "Error: usage: ADD, SEARCH, EXIT" << std::endl;
			sleep(2);
		}
	}
	return (0);
}
