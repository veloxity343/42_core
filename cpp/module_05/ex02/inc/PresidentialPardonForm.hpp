#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
private:
	const std::string target;
	void executeForm() const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm(std::string);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	~PresidentialPardonForm();
};
