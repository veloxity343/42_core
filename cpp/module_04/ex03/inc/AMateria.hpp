/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:09 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
