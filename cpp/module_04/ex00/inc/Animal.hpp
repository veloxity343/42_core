/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:02:43 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:02:44 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &copy);

		virtual ~Animal();

		Animal &operator=(const Animal &src);

		virtual void makeSound(void)const;

		std::string getType(void)const;
};
