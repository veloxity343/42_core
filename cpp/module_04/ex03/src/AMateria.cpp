/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:24 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:25 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria object created" << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
	std::cout << "AMateria object copied" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria object destroyed" << std::endl;
}

AMateria const	&AMateria::operator=(AMateria const &copy)
{
	this->_type = copy._type;
	std::cout << "AMateria assignment operator called" << std::endl;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}
