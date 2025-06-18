#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main (void) {
	try {
		Bureaucrat newbie("Newbie John", 145);
		Bureaucrat manager("Manager Hans", 40);
		Bureaucrat smanager("Senior Manager Carrie", 70);
		Bureaucrat boss("The Boss", 1);
		ShrubberyCreationForm shrub("home");
		ShrubberyCreationForm shrub2(shrub);
		RobotomyRequestForm robo("Johnny");
		PresidentialPardonForm pres("Bob");

		std::cout << "--Shrubbery Form Test--\n";
		std::cout << shrub2;
		manager.executeForm(shrub2);
		newbie.signForm(shrub2);
		newbie.executeForm(shrub2);
		smanager.executeForm(shrub2);
		manager.executeForm(shrub2);

		std::cout << "--Robotomy Form Test--\n";
		newbie.signForm(robo);
		smanager.signForm(robo);
		manager.executeForm(robo);

		std::cout << "--Presidential Pardon Form Test--\n";
		smanager.signForm(pres);
		boss.signForm(pres);
		boss.executeForm(pres);
		
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
