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
