#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

void testMakeForms(std::string form_name)
{
	static Intern		someRandomIntern;
	static Bureaucrat	manager("Alice", 40);

	try {
		AForm *form = someRandomIntern.makeForm(form_name, "Bender");

		manager.signForm(*form);
		manager.executeForm(*form);
		delete form;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main (void) {
	testMakeForms("Shrubbery Creation Form");
	testMakeForms("Robotomy Request Form");
	testMakeForms("Presidential Pardon Form");
	testMakeForms("Weird Form");

	return (0);
}
