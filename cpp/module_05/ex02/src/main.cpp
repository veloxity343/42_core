#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat newbie("Newbie John", 145);
		Bureaucrat manager("Manager Hans", 40);
		Bureaucrat smanager("Senior Manager Carrie", 70);
		Bureaucrat boss("The Boss", 1);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Johnny");
		PresidentialPardonForm pres("Bob");

		std::vector<AForm*> forms;
		forms.push_back(&shrub);
		forms.push_back(&robo);
		forms.push_back(&pres);

		std::vector<Bureaucrat*> bureaucrats;
		bureaucrats.push_back(&newbie);
		bureaucrats.push_back(&smanager);
		bureaucrats.push_back(&manager);
		bureaucrats.push_back(&boss);

		while (true) {
			std::string input;
			std::cout << "Available Bureaucrats:\n";
			for (size_t i = 0; i < bureaucrats.size(); ++i)
				std::cout << "[" << i << "] " << *bureaucrats[i] << "\n";

			std::cout << "Select bureaucrat index (or type 'q' to quit): ";
			std::getline(std::cin, input);
			if (input == "q") break;

			int b_idx = std::atoi(input.c_str());
			if (b_idx < 0 || static_cast<size_t>(b_idx) >= bureaucrats.size()) {
				std::cout << "Invalid bureaucrat index.\n";
				continue;
			}

			Bureaucrat& actor = *bureaucrats[b_idx];

			std::cout << "\nAvailable Forms:\n";
			for (size_t i = 0; i < forms.size(); ++i)
				std::cout << "[" << i << "] " << *forms[i] << "\n";

			std::cout << "Select form index (or type 'b' to go back): ";
			std::getline(std::cin, input);
			if (input == "b") continue;

			int f_idx = std::atoi(input.c_str());
			if (f_idx < 0 || static_cast<size_t>(f_idx) >= forms.size()) {
				std::cout << "Invalid form index.\n";
				continue;
			}

			AForm& selectedForm = *forms[f_idx];

			while (true) {
				std::cout << "\nSelected: Bureaucrat = " << actor.getName()
				          << ", Form = " << selectedForm.getName() << "\n";
				std::cout << "[s] Sign form\n";
				std::cout << "[e] Execute form\n";
				std::cout << "[b] Back to bureaucrat selection\n";
				std::cout << "[q] Quit program\n";
				std::cout << "Enter choice: ";

				std::getline(std::cin, input);

				if (input == "q")
					return 0;
				else if (input == "b")
					break;
				else if (input == "s") {
					actor.signForm(selectedForm);
				}
				else if (input == "e") {
					actor.executeForm(selectedForm);
				}
				else {
					std::cout << "Invalid input.\n";
				}
			}
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
