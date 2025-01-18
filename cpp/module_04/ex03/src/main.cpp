/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:37 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:38 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <vector>
#include <ctime>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void initializeHp(std::map<std::string, int> &hpMap, ICharacter &character, int maxHp)
{
	hpMap[character.getName()] = maxHp;
}

void attack(std::map<std::string, int> &hpMap, ICharacter &attacker, ICharacter &target)
{
	MateriaSource materiaSource;
	materiaSource.learnMateria(new Ice());
	if (hpMap[target.getName()] <= 0)
	{
		std::cout << attacker.getName() << " attacks " << target.getName()
				<< " but " << target.getName() << " is already dead!" << std::endl;
		return ;
	}
	else if (hpMap[attacker.getName()] <= 0)
	{
		std::cout << attacker.getName() << " cannot attack because "
				<< attacker.getName() << " is already dead!" << std::endl;
		return ;
	}

	int damage = (rand() % 3) + 1;
	attacker.use(0, target);
	hpMap[target.getName()] -= damage;
	if (hpMap[target.getName()] < 0)
		hpMap[target.getName()] = 0;

	std::cout << attacker.getName() << " attacks " << target.getName()
			<< " for " << damage << " damage!" << std::endl;
	std::cout << target.getName() << " now has " << hpMap[target.getName()] << " HP." << std::endl;
	attacker.unequip(0);
	attacker.equip(materiaSource.createMateria("Ice"));
}

void healLowestHp(std::map<std::string, int> &hpMap, ICharacter &healer, ICharacter &c1, ICharacter &c2)
{
	MateriaSource materiaSource;
	materiaSource.learnMateria(new Cure());
	ICharacter *toHeal = &c1;

	if (hpMap[c2.getName()] < hpMap[c1.getName()])
		toHeal = &c2;
	
	if (hpMap[toHeal->getName()] <= 0)
	{
		std::cout << toHeal->getName() << " cannot be healed because "
				<< toHeal->getName() << " is already dead!" << std::endl;
		return ;
	}

	int healAmount = (rand() % 2) + 1;
	healer.use(1, *toHeal);
	hpMap[toHeal->getName()] += healAmount;
	std::cout << healer.getName() << " heals " << toHeal->getName()
			  << " for " << healAmount << " HP!" << std::endl;
	std::cout << toHeal->getName() << " now has " << hpMap[toHeal->getName()] << " HP." << std::endl;
	healer.unequip(1);
	healer.equip(materiaSource.createMateria("Cure"));
}

AMateria *generateRandomMateria(MateriaSource &materiaSource)
{
	if (rand() % 2 == 0)
		return (materiaSource.createMateria("Ice"));
	return (materiaSource.createMateria("Cure"));
}

int main(int argc, char **argv)
{
	std::srand(std::time(0));

	if (argc < 3)
	{
		std::cout << "Usage: " << argv[0] << " Adventurer1 Adventurer2" << std::endl;
		return 1;
	}

	std::cout << "\033[1;33m** Constructing **\033[0m" << std::endl;
	Character adventurer1(argv[1]);
	Character adventurer2(argv[2]);

	std::vector<std::string> enemyNames;
	enemyNames.push_back("Hobgoblin");
	enemyNames.push_back("Kobold");
	enemyNames.push_back("Slime");

	Character enemy1(enemyNames[rand() % enemyNames.size()]);
	Character enemy2(enemyNames[rand() % enemyNames.size()]);

	std::map<std::string, int> hpMap;
	initializeHp(hpMap, adventurer1, 10);
	initializeHp(hpMap, adventurer2, 10);
	initializeHp(hpMap, enemy1, 10);
	initializeHp(hpMap, enemy2, 10);

	MateriaSource materiaSource;
	materiaSource.learnMateria(new Ice());
	materiaSource.learnMateria(new Cure());

	for (int i = 0; i < 2; ++i)
	{
		adventurer1.equip(materiaSource.createMateria("Ice"));
		adventurer1.equip(materiaSource.createMateria("Cure"));
		adventurer2.equip(materiaSource.createMateria("Ice"));
		adventurer2.equip(materiaSource.createMateria("Cure"));
		enemy1.equip(materiaSource.createMateria("Ice"));
		enemy1.equip(materiaSource.createMateria("Cure"));
		enemy2.equip(materiaSource.createMateria("Ice"));
		enemy2.equip(materiaSource.createMateria("Cure"));
	}

	std::cout << "\033[1;34mLet the adventure commence!\033[0m" << std::endl;
	std::cout << "\033[1;33mThe adventurers " << adventurer1.getName() << " and " << 
			adventurer2.getName() << " encounter enemies " << enemy1.getName() << " and " << 
			enemy2.getName() << ".\033[0m" << std::endl;
	bool adventurersTurn = true;
	while ((hpMap[adventurer1.getName()] > 0 || hpMap[adventurer2.getName()] > 0) &&
			(hpMap[enemy1.getName()] > 0 || hpMap[enemy2.getName()] > 0))
	{
		if (adventurersTurn)
		{
			if (hpMap[adventurer1.getName()] > 0)
				attack(hpMap, adventurer1, enemy1);
			if (hpMap[adventurer2.getName()] > 0)
				attack(hpMap, adventurer2, enemy2);
		}
		else
		{
			if (hpMap[enemy1.getName()] > 0)
				attack(hpMap, enemy1, adventurer1);
			if (hpMap[enemy2.getName()] > 0)
				attack(hpMap, enemy2, adventurer2);
		}

		adventurersTurn = !adventurersTurn;

		if (adventurersTurn)
		{
			if (hpMap[adventurer1.getName()] > 0 && hpMap[adventurer2.getName()] > 0)
				healLowestHp(hpMap, adventurer1, adventurer1, adventurer2);
		}
		else
		{
			if (hpMap[enemy1.getName()] > 0 && hpMap[enemy2.getName()] > 0)
				healLowestHp(hpMap, enemy1, enemy1, enemy2);
		}
	}

	if (hpMap[adventurer1.getName()] <= 0 && hpMap[adventurer2.getName()] <= 0)
		std::cout << "\033[1;31mThe dungeon delving ends here...\033[0m" << std::endl;
	else if (hpMap[enemy1.getName()] <= 0 && hpMap[enemy2.getName()] <= 0)
		std::cout << "\033[1;32mThe adventurers have triumphed!\033[0m" << std::endl;

	std::cout << "\033[1;33m** Destructing **\033[0m" << std::endl;
	return (0);
}
