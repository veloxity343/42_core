/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:14:05 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/09 10:47:50 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/* #include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
    system("clear");
    if (argc != 5)
	{
        std::cerr << "Usage: " << argv[0] << " <HumanA name> <HumanA weapon> <HumanB name> <HumanB weapon (or 'none')>" << std::endl;
        return (EXIT_FAILURE);
    }
    std::srand(std::time(0));
	
    std::string humanAName = "\033[1;36m" + std::string(argv[1]) + "\033[0m";
    std::string humanAWeaponType = argv[2];
    Weapon weaponA(humanAWeaponType);
    HumanA humanA(humanAName, weaponA);

    std::string humanBName = "\033[1;35m" + std::string(argv[3]) + "\033[0m";
    std::string humanBWeaponType = argv[4];
    HumanB humanB(humanBName);
    Weapon *weaponB = nullptr;
    if (humanBWeaponType != "none")
	{
        weaponB = new Weapon(humanBWeaponType);
        humanB.setWeapon(*weaponB);
    }

    int humanAHealth = 10;
    int humanBHealth = 10;
    std::cout << "\n\033[1;32m--- Fight begins! ---\033[0m\n" << std::endl;
    while (humanAHealth > 0 && humanBHealth > 0)
	{
        humanA.attack();
        if (std::rand() % 100 < 80)
		{
            int damage = 2 + (std::rand() % 3 - 1);
            humanBHealth -= damage;
            std::cout << humanAName << " hits for " << damage << " damage!" << std::endl;
        }
		else
            std::cout << humanAName << " misses!" << std::endl;
        std::cout << humanBName << "'s health: " << humanBHealth << std::endl << std::endl;
        if (humanBHealth <= 0)
		{
            std::cout << humanBName << " is \033[1;31mdefeated\033[0m!" << std::endl;
            break;
        }

        humanB.attack();
		if (weaponB)
		{
			if (std::rand() % 100 < 70)
			{
				int damage = 2 + (std::rand() % 3 - 1);
				humanAHealth -= damage;
				std::cout << humanBName << " hits for " << damage << " damage!" << std::endl;
			}
			else
				std::cout << humanBName << " misses!" << std::endl;
		}
		else
		{
			humanAHealth -= 1;
			std::cout << humanBName << " hits for 1 damage! (unarmed)" << std::endl;
		}
        std::cout << humanAName << "'s health: " << humanAHealth << std::endl << std::endl;
        if (humanAHealth <= 0)
		{
            std::cout << humanAName << " is \033[1;31mdefeated\033[0m!" << std::endl;
            break;
        }
    }

    if (weaponB)
        delete weaponB;
    return (0);
} */
