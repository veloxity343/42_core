/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:02 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 13:43:57 by rcheong          ###   ########.fr       */
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

	// display_welcome();
	while (1)
	{
		system("clear");
		display_menu_and_prompt(input);
		for (std::string::size_type i = 0; i < input.length(); ++i)
            input[i] = std::toupper(static_cast<unsigned char>(input[i]));
		if (input.empty())
			continue ;
		else if (input == "EXIT")
			return (system("clear"), 0);
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
		{
			std::cout << "Error: Please try a valid command." << std::endl;
			sleep(2);
		}
	}
	return (0);
}
