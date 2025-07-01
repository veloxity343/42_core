#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try {
		// Create initial form objects
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Johnny");
		PresidentialPardonForm pres("Bob");

		std::vector<AForm*> forms;
		forms.push_back(&shrub);
		forms.push_back(&robo);
		forms.push_back(&pres);

		// Create bureaucrats
		Bureaucrat newbie("Newbie John", 145);
		Bureaucrat manager("Manager Hans", 40);
		Bureaucrat smanager("Senior Manager Carrie", 70);
		Bureaucrat boss("The Boss", 1);

		std::vector<Bureaucrat*> bureaucrats;
		bureaucrats.push_back(&newbie);
		bureaucrats.push_back(&smanager);
		bureaucrats.push_back(&manager);
		bureaucrats.push_back(&boss);

		while (true) {
			std::string input;
			std::cout << "\nAvailable Bureaucrats:\n";
			for (size_t i = 0; i < bureaucrats.size(); ++i)
				std::cout << "[" << i + 1 << "] " << *bureaucrats[i] << "\n";
			std::cout << "Select bureaucrat index (or type 'q' to quit): ";
			std::getline(std::cin, input);
			if (input == "q")
				break;

			int b_idx = std::atoi(input.c_str()) - 1;
			if (b_idx < 0 || static_cast<size_t>(b_idx) >= bureaucrats.size()) {
				std::cout << "Invalid index.\n";
				continue;
			}

			Bureaucrat& actor = *bureaucrats[b_idx];

			while (true) {
				std::cout << "\nSelected Bureaucrat: " << actor.getName() << "\n";
				// std::cout << "\nAvailable Forms:\n";
				// for (size_t i = 0; i < forms.size(); ++i)
				// 	std::cout << "[" << i + 1 << "] " << *forms[i];
				// std::cout << std::endl;

				std::cout << "[s] Sign a form\n";
				std::cout << "[e] Execute a form\n";
				std::cout << "[r] Reset all forms\n";
				std::cout << "[b] Back to Bureaucrat selection\n";
				std::cout << "[q] Quit program\n";
				std::cout << "Enter choice: ";

				std::getline(std::cin, input);

				if (input == "q")
					return 0;
				else if (input == "b")
					break;
				else if (input == "r") {
					shrub = ShrubberyCreationForm("home");
					robo = RobotomyRequestForm("Johnny");
					pres = PresidentialPardonForm("Bob");
					std::cout << "Forms have been reset.\n";
					std::cout << std::endl;
					for (size_t i = 0; i < forms.size(); ++i)
						std::cout << "[" << i + 1 << "] " << *forms[i];
				}
				else if (input == "s" || input == "e") {
					std::string indexStr;
					std::cout << "\nAvailable Forms:\n";
					for (size_t i = 0; i < forms.size(); ++i)
						std::cout << "[" << i + 1 << "] " << *forms[i];
					std::cout << "Enter form index: ";
					std::getline(std::cin, indexStr);
					int f_idx = std::atoi(indexStr.c_str()) - 1;
					if (f_idx < 0 || static_cast<size_t>(f_idx) >= forms.size()) {
						std::cout << "Invalid form index.\n";
						continue;
					}

					if (input == "s") {
						actor.signForm(*forms[f_idx]);
						std::cout << std::endl;
						for (size_t i = 0; i < forms.size(); ++i)
							std::cout << "[" << i + 1 << "] " << *forms[i];
					} else {
						actor.executeForm(*forms[f_idx]);
						std::cout << std::endl;
						for (size_t i = 0; i < forms.size(); ++i)
							std::cout << "[" << i + 1 << "] " << *forms[i];
					}
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
