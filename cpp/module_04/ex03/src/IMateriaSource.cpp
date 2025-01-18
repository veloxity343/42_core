#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource object created with default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &copy)
{
	*this = copy;
	std::cout << "IMateriaSource object copied" << std::endl;
}

IMateriaSource const	&IMateriaSource::operator=(IMateriaSource const &copy)
{
	(void)copy;
	std::cout << "IMateriaSource assignment operator called" << std::endl;
	return (*this);
}
