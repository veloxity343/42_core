/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:13 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:14 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);

		Cure const	&operator=(Cure const &copy);

		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);
};
