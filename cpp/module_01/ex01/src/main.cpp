/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:06:55 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/09 10:27:58 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Demonstrates dynamic memory allocation using the `new[]` operator.
 * @details This program demonstrates how dynamic memory allocation is used to 
 * create an array of `Zombie` objects on the heap. The `new[]` operator allocates 
 * memory at runtime for the required number of zombies, while the `delete[]` operator 
 * ensures that the memory is freed when it is no longer needed.
 * The exercise demonstrates the following:
 * - How to allocate memory dynamically for an array of objects (`Zombie *horde = new Zombie[N]`).
 * - How to properly deallocate the memory to avoid memory leaks (`delete[] horde`).
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <number of zombies>" << std::endl;
		return (EXIT_FAILURE);
	}
	int zombieAmount = std::atoi(argv[1]);
	if (zombieAmount < 1)
	{
		std::cerr << "Error: A Horde cannot contain less than one zombie." << std::endl;
		return (EXIT_FAILURE);
	}
	Zombie *horde = zombieHorde(zombieAmount, "Horde Member");
	if (horde == NULL)
		return (EXIT_FAILURE);
	for (int i = 0; i < zombieAmount; ++i)
		horde[i].announce();
	delete[] horde;
	return (EXIT_SUCCESS);
}
