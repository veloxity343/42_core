#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>
#include <sstream>
#include <vector>

static int my_stoi(const std::string& s) {
	std::istringstream iss(s);
	int result;
	char leftover;

	if (!(iss >> result) || (iss >> leftover)) {
		throw std::invalid_argument("Invalid input for integer conversion");
	}
	return result;
}

int main() {
	try {
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Johnny");
		PresidentialPardonForm pres("Bob");

		std::vector<AForm*> forms;
		forms.push_back(&shrub);
		forms.push_back(&robo);
		forms.push_back(&pres);

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
			std::string command;
			std::cout << "\n--- Main Menu ---\n";
			std::cout << "[1] Sign a form\n";
			std::cout << "[2] Execute a form\n";
			std::cout << "[3] Reset all forms\n";
			std::cout << "[4] List forms\n";
			std::cout << "[5] List bureaucrats\n";
			std::cout << "[q] Quit\n";
			std::cout << "Enter your choice: ";
			std::getline(std::cin, command);

			if (command == "q")
				break;

			if (command == "1" || command == "2") {
				if (forms.empty()) {
					std::cout << "No forms available.\n";
					continue;
				}

				std::cout << "\nAvailable Bureaucrats:\n";
				for (size_t i = 0; i < bureaucrats.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *bureaucrats[i] << "\n";
				std::cout << "Select bureaucrat index: ";
				std::string input;
				std::getline(std::cin, input);

				int b_idx = -1;
				try {
					b_idx = my_stoi(input) - 1;
					if (b_idx < 0 || static_cast<size_t>(b_idx) >= bureaucrats.size()) {
						std::cout << "Invalid index.\n";
						continue;
					}
				} catch (...) {
					std::cout << "Invalid input.\n";
					continue;
				}
				Bureaucrat& actor = *bureaucrats[b_idx];

				std::cout << "\nAvailable Forms:\n";
				for (size_t i = 0; i < forms.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *forms[i];
				std::cout << "Select form index: ";
				std::getline(std::cin, input);

				int f_idx = -1;
				try {
					f_idx = my_stoi(input) - 1;
					if (f_idx < 0 || static_cast<size_t>(f_idx) >= forms.size()) {
						std::cout << "Invalid form index.\n";
						continue;
					}
				} catch (...) {
					std::cout << "Invalid input.\n";
					continue;
				}

				if (command == "1")
					actor.signForm(*forms[f_idx]);
				else
					actor.executeForm(*forms[f_idx]);
			}

			else if (command == "3") {
				shrub = ShrubberyCreationForm("home");
				robo = RobotomyRequestForm("Johnny");
				pres = PresidentialPardonForm("Bob");

				forms.clear();
				forms.push_back(&shrub);
				forms.push_back(&robo);
				forms.push_back(&pres);

				std::cout << "Forms have been reset.\n";
			}

			else if (command == "4") {
				std::cout << "\n--- Forms ---\n";
				for (size_t i = 0; i < forms.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *forms[i];
			}

			else if (command == "5") {
				std::cout << "\n--- Bureaucrats ---\n";
				for (size_t i = 0; i < bureaucrats.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *bureaucrats[i] << "\n";
			}

			else {
				std::cout << "Invalid command.\n";
			}
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
