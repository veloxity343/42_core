#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
private:
	const std::string target;
	void executeForm() const;
public:
	//constructors, destructors and assignment overload
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm(std::string);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	~PresidentialPardonForm();
};
