#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		unsigned int getMaxHitPoints() const;

	private:
		bool _guard_mode;

	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &src);
		
		void attack(const std::string &target);
		void guardGate();
		
		bool getGuardMode() const;
		
		void setGuardMode(bool mode);
};
