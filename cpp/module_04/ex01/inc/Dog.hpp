/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:03:21 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:03:22 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &copy);

		~Dog();

		Dog &operator=(const Dog &src);

		void makeSound(void)const;

		void getIdea(void)const;

		void setIdea(size_t i, std::string idea);
};
