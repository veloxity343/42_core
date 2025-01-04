#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
	_name = "default";
	_hit_pts = FragTrap::_hit_pts;
	_energy_pts = ScavTrap::_energy_pts;
	_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hit_pts = FragTrap::_hit_pts;
	_energy_pts = ScavTrap::_energy_pts;
	_attack_dmg = FragTrap::_attack_dmg;
	std::cout << "DiamondTrap constructor for " << _name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor for " << _name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
		_name = src._name;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

unsigned int DiamondTrap::getMaxHitPoints() const
{
	return (FragTrap::getMaxHitPoints());
}
