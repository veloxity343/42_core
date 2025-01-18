/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:06:20 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:06:21 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		IMateriaSource(void);
		IMateriaSource(IMateriaSource const &copy);

		IMateriaSource const	&operator=(IMateriaSource const &copy);

	public:
		virtual ~IMateriaSource() {}

		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};
