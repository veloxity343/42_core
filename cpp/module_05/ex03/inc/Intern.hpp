#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	~Intern();

	class InvalidFormException: public std::exception {
		const char* what() const throw();
	};
	AForm* makeForm(std::string, std::string);
};
