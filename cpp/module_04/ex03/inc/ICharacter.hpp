/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:18 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:19 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter
{
	protected:
		ICharacter(void);
		ICharacter(ICharacter const &copy);

		ICharacter const	&operator=(ICharacter const &copy);

	public:
		virtual	~ICharacter() {}

		virtual std::string const	&getName() const = 0;

		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};
