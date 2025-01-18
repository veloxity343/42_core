/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:35 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:36 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
