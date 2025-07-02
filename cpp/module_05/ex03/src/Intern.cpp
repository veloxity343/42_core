#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& i) { *this = i; }

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return (*this);
}

Intern::~Intern() {}

const char* Intern::InvalidFormException::what() const throw() {
	return ("Form name doesn't exist.");
}

AForm *Intern::makeForm(std::string formtype, std::string target) {
	AForm* newform;
	const std::string forms[3] = {"Shrubbery Creation Form", "Robotomy Request Form", "Presidential Pardon Form"};
	size_t i;

	for (i = 0; i < 3; ++i)
		if (formtype == forms[i])
			break;
	
	switch (i) {
		case 0:
		newform = new ShrubberyCreationForm(target);
		break ;
		case 1:
		newform = new RobotomyRequestForm(target);
		break ;
		case 2:
		newform = new PresidentialPardonForm(target);
		break ;
		default:
			throw InvalidFormException();
			return NULL;
	}
	if (newform)
		std::cout << "Intern creates " << newform->getName() << std::endl;
	return (newform);
}
