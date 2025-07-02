#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
private:
	const std::string target;
	void executeForm() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	~ShrubberyCreationForm();
};
