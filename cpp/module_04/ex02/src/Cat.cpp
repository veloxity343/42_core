/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:05:23 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:05:24 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
	if (!this->_brain)
		std::cerr << "Failed to allocate memory for Cat's brain" << std::endl;
}

Cat::Cat(const Cat &copy): AAnimal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete(this->_brain);
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	if (!this->_brain)
		std::cerr << "Failed to allocate memory for Cat's brain" << std::endl;
	return (*this);
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << " says: ** Meow? **" << std::endl;
}

void	Cat::getIdea(void)const
{
	for (int i = 0; i < 3; i++)
		std::cout << "\tIdea " << i << " of the Cat is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

void	Cat::setIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}
