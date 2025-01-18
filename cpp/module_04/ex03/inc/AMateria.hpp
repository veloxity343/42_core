#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		AMateria(std::string const &type);
		AMateria(AMateria const &copy);

	public:
		virtual ~AMateria(void);

		AMateria const	&operator=(AMateria const &copy);

		std::string const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target) = 0;
};
