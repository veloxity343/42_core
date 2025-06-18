#include "../inc/Bureaucrat.hpp"
#include <iostream>

void testConstructor(int grade)
{
	try {
		Bureaucrat bu("Randy", grade);
		std::cout << bu << " sucessfully created\n";
	}
	catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testDecrement(int startgrade)
{
	try {
		Bureaucrat bu("Mandy", startgrade);
		std::cout << bu << " has been demoted\n";
		bu.decrementGrade();
		std::cout << bu << " has been demoted\n";
		bu.decrementGrade();
		std::cout << bu << " has been demoted\n";
		bu.decrementGrade();
		std::cout << bu << std::endl;
	}
	catch (std::exception& except) { //giving the exception different name to show that it is a variable
		std::cerr << "Exception: " << except.what() << std::endl;
	}
}

void testIncrement(int startgrade)
{
	try {
		Bureaucrat bu("Mandy", startgrade);
		std::cout << bu << " has been promoted\n";
		bu.incrementGrade();
		std::cout << bu << " has been promoted\n";
		bu.incrementGrade();
		std::cout << bu << " has been promoted\n";
		bu.incrementGrade();
		std::cout << bu << std::endl;
	}
	catch (std::exception& except) { //giving the exception different name to show that it is a variable
		std::cerr << "Exception: " << except.what() << std::endl;
	}
}
int main (void) {
	std::cout << "--Test Constructor--\n";
	testConstructor(0);
	testConstructor(151);
	testConstructor(3);
	std::cout << "--Test Decrement--\n";
	testDecrement(148);
	testDecrement(1);
	std::cout << "--Test Increment--\n";
	testIncrement(148);
	testIncrement(2);

	return (0);
}
