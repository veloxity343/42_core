#include "ScavTrap.hpp"

/* int main(void)
{
	system("clear");
	ClapTrap clap("Clappy");
	clap.attack("target dummy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	ScavTrap scav("Scavvy");
	scav.attack("enemy bot");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	
	ClapTrap weakClap("Weakling");
	weakClap.takeDamage(15);
	weakClap.beRepaired(5);
	weakClap.attack("nothing");
	
	ScavTrap tiredScav("Tired");
	for (int i = 0; i < 51; ++i)
		tiredScav.attack("target");
	tiredScav.guardGate();
	
	return (0);
} */

int main()
{
	// Introduce the characters
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	std::cout << "\nWelcome to the ultimate showdown!\n";

	// Round 1: ClapTrap attacks ScavTrap
	std::cout << "\nRound 1: ClapTrap attacks ScavTrap!\n";
	clap.attack(scav.getName());
	scav.takeDamage(clap.getAttackDamage());

	// Round 2: ScavTrap counterattacks
	std::cout << "\nRound 2: ScavTrap counterattacks!\n";
	scav.attack(clap.getName());
	clap.takeDamage(scav.getAttackDamage());

	// Round 3: ScavTrap enters Gate Keeper mode
	std::cout << "\nRound 3: ScavTrap activates Gate Keeper mode!\n";
	scav.guardGate();

	// Round 4: ClapTrap tries to repair itself
	std::cout << "\nRound 4: ClapTrap tries to repair itself!\n";
	clap.beRepaired(5);

	// Round 5: ScavTrap keeps attacking
	std::cout << "\nRound 5: ScavTrap launches another attack!\n";
	scav.attack(clap.getName());
	clap.takeDamage(scav.getAttackDamage());

	// Conclusion: Who survives?
	std::cout << "\nThe battle is over! Let's see who's left standing:\n";
	if (clap.getHitPoints() > 0)
		std::cout << clap.getName() << " survives with " << clap.getHitPoints() << " hit points!\n";
	else
		std::cout << clap.getName() << " is out of the fight!\n";

	if (scav.getHitPoints() > 0)
		std::cout << scav.getName() << " survives with " << scav.getHitPoints() << " hit points!\n";
	else
		std::cout << scav.getName() << " is out of the fight!\n";

	return 0;
}
