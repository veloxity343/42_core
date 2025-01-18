/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:04:55 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:04:56 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

class AAnimal
{
	protected:
		std::string _type;
		
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);

		virtual ~AAnimal() = 0;

		AAnimal &operator=(const AAnimal &src);

		virtual void makeSound(void)const;

		std::string getType(void)const;
};
