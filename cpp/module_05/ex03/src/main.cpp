#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <sstream>
#include <vector>

static int my_stoi(const std::string& s) {
	std::istringstream iss(s);
	int result;
	char leftover;
	if (!(iss >> result) || (iss >> leftover))
		throw std::invalid_argument("Invalid input");
	return result;
}

int main() {
	try {
		Intern intern;

		const std::string knownForms[3] = {
			"Shrubbery Creation Form",
			"Robotomy Request Form",
			"Presidential Pardon Form"
		};

		Bureaucrat newbie("Newbie John", 145);
		Bureaucrat manager("Manager Hans", 40);
		Bureaucrat smanager("Senior Manager Carrie", 70);
		Bureaucrat boss("The Boss", 1);

		std::vector<Bureaucrat*> bureaucrats;
		bureaucrats.push_back(&newbie);
		bureaucrats.push_back(&smanager);
		bureaucrats.push_back(&manager);
		bureaucrats.push_back(&boss);

		std::vector<AForm*> forms;

		while (true) {
			std::string input;
			std::string command;

			std::cout << "\n--- Menu ---\n";
			std::cout << "[1] Create new form\n";
			std::cout << "[2] Sign a form\n";
			std::cout << "[3] Execute a form\n";
			std::cout << "[4] List stored forms\n";
			std::cout << "[5] List bureaucrats\n";
			std::cout << "[q] Quit\n";
			std::cout << "Enter choice: ";
			std::getline(std::cin, command);

			if (command == "q")
				break;

			if (command == "1") {
				std::cout << "\nAvailable forms:\n";
				for (int i = 0; i < 3; ++i)
					std::cout << "[" << i + 1 << "] " << knownForms[i] << "\n";
				std::cout << "Enter form index or name: ";
				std::getline(std::cin, input);

				std::string formName;
				try {
					int index = my_stoi(input) - 1;
					if (index >= 0 && index < 3)
						formName = knownForms[index];
					else {
						std::cout << "Invalid index.\n";
						continue;
					}
				} catch (...) {
					formName = input;
				}

				std::string target;
				std::cout << "Enter target for the form: ";
				std::getline(std::cin, target);

				try {
					AForm* form = intern.makeForm(formName, target);
					forms.push_back(form);
				} catch (std::exception& e) {
					std::cout << "Error: " << e.what() << "\n";
				}
			}

			else if (command == "2" || command == "3") {
				if (forms.empty()) {
					std::cout << "No forms available.\n";
					continue;
				}

				std::cout << "\nAvailable bureaucrats:\n";
				for (size_t i = 0; i < bureaucrats.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *bureaucrats[i] << "\n";
				std::cout << "Enter bureaucrat index: ";
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

				std::cout << "\nAvailable forms:\n";
				for (size_t i = 0; i < forms.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *forms[i];

				std::cout << "Enter form index: ";
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

				if (command == "2")
					actor.signForm(*forms[f_idx]);
				else
					actor.executeForm(*forms[f_idx]);
			}

			else if (command == "4") {
				if (forms.empty())
					std::cout << "No forms created yet.\n";
				else {
					std::cout << "\n--- Stored Forms ---\n";
					for (size_t i = 0; i < forms.size(); ++i)
						std::cout << "[" << i + 1 << "] " << *forms[i];
				}
			}

			else if (command == "5") {
				std::cout << "\n--- Bureaucrats ---\n";
				for (size_t i = 0; i < bureaucrats.size(); ++i)
					std::cout << "[" << i + 1 << "] " << *bureaucrats[i] << "\n";
			}

			else {
				std::cout << "Invalid choice.\n";
			}
		}
		for (size_t i = 0; i < forms.size(); ++i)
			delete forms[i];
		forms.clear();
	}
	catch (const std::exception& e) {
		std::cerr << "Fatal Exception: " << e.what() << std::endl;
	}
	return 0;
}
