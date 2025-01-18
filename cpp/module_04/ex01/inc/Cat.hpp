/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:03:19 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:03:20 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &copy);

		~Cat();

		Cat &operator=(const Cat &src);

		void makeSound(void)const;

		void getIdea(void)const;
		
		void setIdea(size_t i, std::string idea);
};
