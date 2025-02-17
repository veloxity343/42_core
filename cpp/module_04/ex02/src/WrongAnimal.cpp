/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:05:32 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:05:33 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("WereBeast")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void WrongAnimal::makeSound(void)const
{
	std::cout << this->getType() << " says: ** incomprehensible screeching **" << std::endl;
}

std::string	WrongAnimal::getType(void)const
{
	return (this->_type);
}
