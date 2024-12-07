/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:17:10 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/06 16:18:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Demonstrates the concepts of heap vs stack memory.
 * @details This program demonstrates the difference between heap and stack memory.
 * The `Zombie` object is allocated on the heap using dynamic memory allocation
 * using new and delete operators, whereas local variables and function parameters
 * are stored on the stack, which is used for temporary data storage (randomChump),
 * whereas the heap is used for objects that need to persist beyond the scope of
 * the function that created them (newZombie).
 */
int	main(void)
{
	Zombie *zombie = newZombie("\033[1;34mProf. Brainztorm\033[0m");
	randomChump("\033[1;33mJeff the Intern\033[0m");
	delete zombie;
	std::cout << "\033[1;32mThe Plants are victorious!\033[0m" << std::endl;
	return (EXIT_SUCCESS);
}
