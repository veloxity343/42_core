#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Prime"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap constructor for the name " << this->_name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor for " << this->_name << " called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else if (getEnergyPoints() == 0)
		std::cout << "\033[31mClapTrap " << getName() << " is not able to attack " << target << " because it has insufficient energy points.\033[0m" << std::endl;
	else
		std::cout << "\033[31mClapTrap " << getName() << " is not able to attack " << target << " because it has insufficient hit points.\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() > amount)
		setHitPoints(getHitPoints() - amount);
	else if (getHitPoints() > 0)
		setHitPoints(0);
	else
	{
		std::cout << "\033[33mClapTrap " << getName() << " is already dead, please stop beating it or we'll have to report you to HR.\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << getName() << " was attacked and lost " << amount << " hit points, it now has " << getHitPoints() << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0 && getHitPoints() + amount <= getMaxHitPoints())
	{
		setHitPoints(getHitPoints() + amount);
		std::cout << "ClapTrap " << getName() << " repaired itself and gained " << amount << " hit points, it now has " << getHitPoints() << " hit points." << std::endl;
		setEnergyPoints(getEnergyPoints() - 1);
	}
	else if (getEnergyPoints() == 0)
	{
		std::cout << "\033[31mClapTrap " << getName() << " is not able to repair itself, because it doesn't have enough energy points.\033[0m" << std::endl;
	}
	else if (getHitPoints() == 0)
	{
		std::cout << "\033[31mClapTrap " << getName() << " is not able to repair itself, because it doesn't have enough hit points.\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[33mClapTrap " << getName() << " can't be repaired to exceed more than " << getMaxHitPoints() << " hit points.\033[0m" << std::endl;
	}
}

std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (_hit_pts);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (_energy_pts);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attack_dmg);
}

unsigned int ClapTrap::getMaxHitPoints() const
{
	return (10);
}

void ClapTrap::setName(const std::string &name)
{
	_name = name;
}

void ClapTrap::setHitPoints(unsigned int hit_pts)
{
	_hit_pts = hit_pts;
}

void ClapTrap::setEnergyPoints(unsigned int energy_pts)
{
	_energy_pts = energy_pts;
}

void ClapTrap::setAttackDamage(unsigned int attack_dmg)
{
	_attack_dmg = attack_dmg;
}
