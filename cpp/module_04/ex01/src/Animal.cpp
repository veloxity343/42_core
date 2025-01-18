/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:03:29 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:03:30 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("Beast")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void Animal::makeSound(void)const
{
	std::cout << " says: ** normal animal sounds **" << std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->_type);
}
