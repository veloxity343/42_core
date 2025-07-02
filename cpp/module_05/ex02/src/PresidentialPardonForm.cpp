#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon Form", 25, 5), target("def") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& shrub):
	AForm(shrub), target(shrub.target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string tg):
	AForm("Presidential Pardon Form", 25, 5), target(tg) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (&rhs != this)
		AForm::operator=(rhs);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeForm() const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
