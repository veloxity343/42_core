#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("Ruby");
	
	dt.attack("Enemy");
	dt.takeDamage(20);
	dt.beRepaired(10);
	dt.highFiveGuys();
	dt.guardGate();
	dt.whoAmI();
	return (0);
}
