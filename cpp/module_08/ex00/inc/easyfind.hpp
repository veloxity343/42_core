#pragma once

#include <exception>
#include <iostream>

class NotFoundExeption: public std::exception
{
	public:
		virtual const char *what() const throw() {
			return ("Error: Given number not within the elements of the container\n");
		}
};

#include "easyfind.tpp"
