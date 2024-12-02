/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:09:38 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/01 13:41:20 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cctype>

int main(void)
{
	system("clear");
	Harl harl;
	
	std::cout << "I would think twice before prompting him with the following." << std::endl;
	std::cout << "Don't say I didn't warn you..." << std::endl << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "Type your input (type EXIT or press Ctrl+D to quit):" << std::endl;
	std::string input;
	while (true)
	{
		std::cout << "input: ";
		if (!getline(std::cin, input))
		{
			std::cerr << "^D" << std::endl;
			break;
		}
		if (input.empty())
			continue;
		for (std::string::size_type i = 0; i < input.length(); ++i)
			input[i] = std::toupper(static_cast<unsigned char>(input[i]));
		if (input == "EXIT")
			break;
		harl.complain(input);
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
