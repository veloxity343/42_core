#include "ClapTrap.hpp"

int main(void)
{
	system("clear");
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Psycho");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		a.attack("Training Dummy");
		std::cout << "The Dummy didn't take too kindly to that and retaliates." << std::endl;
		a.takeDamage(5);
		a.beRepaired(5);
		std::cout << "The Dummy is tired of being called dummy and fires off critical hits." << std::endl;
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("Training Dummy");
		b.beRepaired(3);
		for (int i = 0; i < 11; i++)
			b.attack("Training Dummy");
		b.beRepaired(3);
		std::cout << "The Not-So-Dummy performs a Chun-Li whirlwind kick" << std::endl;
		b.takeDamage(10);
		b.takeDamage(10);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
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
