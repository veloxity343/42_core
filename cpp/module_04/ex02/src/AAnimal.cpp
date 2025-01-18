/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:05:08 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:05:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal():_type("BBeast")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void AAnimal::makeSound(void)const
{
	// std::cout << " says: ** normal animal sounds **" << std::endl;
}

std::string	AAnimal::getType(void)const
{
	return (this->_type);
}
