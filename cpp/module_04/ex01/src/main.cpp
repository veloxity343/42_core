/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:03:39 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:03:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
				std::cerr << "Cat allocation failed" << std::endl;
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
				std::cerr << "Dog allocation failed" << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDestructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);
	
	// Demonstration of deep copy
	std::cout << std::endl << std::endl;
	std::cout << "Demonstrating copy constructor creates deep copy" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();

	if (a == NULL)
		std::cerr << "Allocation failed" << std::endl;

	a->setIdea(0, "I have to sniff it");
	a->setIdea(1, "I have to pee on it");
	a->setIdea(2, "I have to sniff it again");
	a->setIdea(101, "some shit");

	Dog *b = new Dog(*a);
	if (b == NULL)
		std::cerr << "Allocation failed" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdea();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdea();
	std::cout << std::endl;

	std::cout << "\033[34mDestructing b\033[0m" << std::endl;
	delete(b);

	return (0);
}
