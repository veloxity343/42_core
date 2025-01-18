#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	protected:
		unsigned int getMaxHitPoints() const;
	private:
		std::string _diamond_name;

	public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &src);

	void attack(const std::string &target);
	void whoAmI();
};
