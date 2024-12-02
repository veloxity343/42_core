/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:17:10 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/30 12:17:11 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie = newZombie("\033[1;34mProf. Brainztorm\033[0m");
	randomChump("\033[1;33mJeff the Intern\033[0m");
	delete zombie;
	std::cout << "\033[1;32mThe Plants are victorious!\033[0m" << std::endl;
	return (EXIT_SUCCESS);
}
