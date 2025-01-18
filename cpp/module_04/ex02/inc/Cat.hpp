/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:05:00 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:05:01 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
