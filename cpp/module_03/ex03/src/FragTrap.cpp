#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap constructor for the name " << getName() << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor for " << getName() << " called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void	FragTrap::highFiveGuys() const
{
	std::cout << "FragTrap " << getName() << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}

unsigned int FragTrap::getMaxHitPoints() const
{
	return (100);
}
