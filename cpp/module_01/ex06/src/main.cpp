/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:45:21 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/02 11:21:54 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cctype>

int	main(int argc, char **argv)
{
	system("clear");
	Harl harl;

	if (argc != 2)
		harl.complain("default");
	else
	{
		for (std::string::size_type i = 0; i < strlen(argv[1]); ++i)
			argv[1][i] = std::toupper(static_cast<unsigned char>(argv[1][i]));
		harl.complain(argv[1]);
	}
	return (EXIT_SUCCESS);
}
