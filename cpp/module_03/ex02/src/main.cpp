#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== ClapTrap Testing =====" << std::endl;
	ClapTrap clap1("Clappy");
	ClapTrap clap2;

	clap1.attack("Target A");
	clap1.takeDamage(3);
	clap1.beRepaired(5);

	clap2.setName("Helper");
	clap2.attack("Target B");
	clap2.takeDamage(12);
	clap2.beRepaired(7);

	std::cout << "\n===== ScavTrap Testing =====" << std::endl;
	ScavTrap scav1("Scavvy");
	ScavTrap scav2;

	scav1.attack("Enemy A");
	scav1.takeDamage(15);
	scav1.beRepaired(20);
	scav1.guardGate();

	scav2.setName("Defender");
	scav2.attack("Enemy B");
	scav2.takeDamage(8);
	scav2.beRepaired(10);

	std::cout << "\n===== FragTrap Testing =====" << std::endl;
	FragTrap frag1("Fraggy");
	FragTrap frag2;

	frag1.attack("Villain A");
	frag1.takeDamage(25);
	frag1.beRepaired(30);
	frag1.highFiveGuys();

	frag2.setName("Boomer");
	frag2.attack("Villain B");
	frag2.takeDamage(50);
	frag2.beRepaired(40);
	frag2.highFiveGuys();

	std::cout << "\n===== Destructor Calls =====" << std::endl;

	return (0);
}
