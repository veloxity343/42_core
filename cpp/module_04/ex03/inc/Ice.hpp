/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:16 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:17 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);

		Ice const	&operator=(Ice const &copy);

		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};
