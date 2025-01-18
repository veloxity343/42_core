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
