/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:32 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:33 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter object created with default constructor" << std::endl;
}

ICharacter::ICharacter(ICharacter const &copy)
{
	*this = copy;
	std::cout << "ICharacter object copied" << std::endl;
}

ICharacter const	&ICharacter::operator=(ICharacter const &copy)
{
	(void)copy;
	std::cout << "ICharacter assignment operator called" << std::endl;
	return (*this);
}
