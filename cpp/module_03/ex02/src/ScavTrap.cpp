#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guard_mode(false)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guard_mode(false)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap constructor for the name " << getName() << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor for " << getName() << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
		setGuardMode(src.getGuardMode());
	}
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else if (getEnergyPoints() == 0)
		std::cout << "\033[31mScavTrap " << getName() << " cannot attack " << target << " because it has insufficient energy points.\033[0m" << std::endl;
	else
		std::cout << "\033[31mScavTrap " << getName() << " cannot attack " << target << " because it has insufficient hit points.\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
	if (!_guard_mode)
	{
		_guard_mode = true;
		std::cout << "ScavTrap " << getName() << " has entered Gate Keeper mode." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " is already in Gate Keeper mode." << std::endl;
	}
}

bool ScavTrap::getGuardMode() const
{
	return (_guard_mode);
}

unsigned int ScavTrap::getMaxHitPoints() const
{
	return (100);
}

void ScavTrap::setGuardMode(bool mode)
{
	_guard_mode = mode;
}
