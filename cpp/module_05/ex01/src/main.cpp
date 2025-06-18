#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

void testMakeForms(int gts, int gte)
{
	try {
		Form testform("Test", gts, gte);
		std::cout << testform << "\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testSignForms(Bureaucrat& bureau, Form form) // Form passed by value (calls copy constructor)
{
	std::cout << bureau << " signing " << form << "\n";
	bureau.signForm(form);
}

int main (void) {
	Bureaucrat a("John", 20);
	Bureaucrat b("Hans", 40);
	Bureaucrat c("Carrie", 100);

	std::cout << "--Test Form Constructor--\n";
	testMakeForms(151, 10);
	testMakeForms(10, 151);
	testMakeForms(10, 0);
	testMakeForms(0, 151);
	testMakeForms(1, 150);
	std::cout << "--Test Sign Forms--\n";
	Form vacay_form("Vacation Form", 30, 10);
	testSignForms(a, vacay_form);
	testSignForms(b, vacay_form);
	testSignForms(c, vacay_form);
	std::cout << "--Test Repeat Sign--\n";
	a.signForm(vacay_form);
	b.signForm(vacay_form);

	return (0);
}
