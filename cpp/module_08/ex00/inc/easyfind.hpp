#pragma once

#include <exception>
#include <iostream>

class NotFoundException: public std::exception {
public:
	virtual const char *what() const throw() {
		return ("Error: Int not found in container\n");
	}
};

#include "easyfind.tpp"
