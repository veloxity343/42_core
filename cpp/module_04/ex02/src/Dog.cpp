/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:05:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:05:29 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (!this->_brain)
		std::cerr << "Failed to allocate memory for Dog's brain" << std::endl;
}

Dog::Dog(const Dog &copy): AAnimal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete(this->_brain);
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	if (!this->_brain)
		std::cerr << "Failed to allocate memory for Dog's brain" << std::endl;
	return (*this);
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << " says: ** Woof! **" << std::endl;
}

void	Dog::getIdea(void)const
{
	for (int i = 0; i < 3; i++)
		std::cout << "\tIdea " << i << " of the Dog is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}
