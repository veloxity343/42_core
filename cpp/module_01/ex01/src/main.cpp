/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:06:55 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/27 11:06:56 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
		return EXIT_FAILURE;
	for (int i = 0; i < zombieAmount; ++i)
		horde[i].announce();
	delete[] horde;
	horde = zombieHorde(0, "Failed");
	return (EXIT_SUCCESS);
}
