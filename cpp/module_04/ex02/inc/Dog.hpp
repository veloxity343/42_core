/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:05:02 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:05:03 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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
