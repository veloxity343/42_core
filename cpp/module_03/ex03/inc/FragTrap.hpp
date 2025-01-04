#pragma once

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		unsigned int getMaxHitPoints() const;
		
	public:
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(const std::string &name);
		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &src);

		void highFiveGuys() const;
};
