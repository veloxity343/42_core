/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:45:24 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/06 15:43:26 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "\033[1;31mA wild Harl has appeared!\033[0m" << std::endl;
	std::cout << "Think of him as a male Karen." << std::endl << std::endl;
}

Harl::~Harl()
{
	std::cout << std::endl;
	std::cout << "\033[1;32mThe manager has expelled Harl from the mortal realm!\033[0m" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "\033[1;34m[DEBUG]\033[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "\033[1;34m[INFO]\033[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "\033[1;34m[WARNING]\033[0m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "\033[1;34m[ERROR]\033[0m" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * @brief Handles complaints based on the specified severity level.
 * @param level A string indicating the severity level ("DEBUG", "INFO", "WARNING", "ERROR").
 * @details This function uses a pointer-to-member-function array to map severity levels 
 *          to their corresponding member functions (`debug`, `info`, `warning`, `error`). 
 *          It compares the input `level` to a predefined list of complaint levels.
 *          - If a match is found, it executes the corresponding function(s) based on the 
 *            severity level using a `switch` statement.
 *          - If the input `level` doesn't match any predefined level, it outputs a default 
 *            message.
 *          The use of `FALLTHROUGH` ensures that, for each case, subsequent severity levels 
 *          are also executed sequentially (cascading complaints).
 * @note The function demonstrates a practical use of pointer-to-member functions and 
 *       efficient control flow with arrays and `switch` statements.
 */
void	Harl::complain(std::string level)
{
	void (Harl::*complainPtr[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complaints[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; i < 4; i++)
	{
		if (complaints[i] == level)
			break ;
	}
	switch(i)
	{
		case(0):
			(this->*complainPtr[0])();
			FALLTHROUGH;
		case(1):
			(this->*complainPtr[1])();
			FALLTHROUGH;
		case(2):
			(this->*complainPtr[2])();
			FALLTHROUGH;
		case(3):
			(this->*complainPtr[3])();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
