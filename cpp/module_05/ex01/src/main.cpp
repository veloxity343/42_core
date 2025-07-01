#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <sstream>
#include <vector>

int my_stoi(const std::string& s) {
	std::istringstream iss(s);
	int result;
	char leftover;
	if (!(iss >> result) || (iss >> leftover))
		throw std::invalid_argument("Invalid input for integer conversion");
	return result;
}

int main() {
	while (true) {
		std::string name;
		std::string gradeInput;
		int grade;

		std::cout << "\n=== Create a Bureaucrat ===\n";
		std::cout << "(Type 'quit' at any time to exit)\n";

		std::cout << "Enter Bureaucrat name: ";
		std::getline(std::cin, name);
		if (name == "quit")
			break;

		std::cout << "Enter Bureaucrat grade (1-150): ";
		std::getline(std::cin, gradeInput);
		if (gradeInput == "quit")
			break;

		try {
			grade = my_stoi(gradeInput);
			Bureaucrat b(name, grade);
			std::cout << "\nCreated Bureaucrat: " << b << "\n";

			std::vector<Form> forms;

			while (true) {
				std::string fname, signGradeStr, execGradeStr;
				int signGrade, execGrade;

				std::cout << "\n=== Create a Form ===\n";
				std::cout << "(Type 'b' to go back to bureaucrat creation)\n";

				std::cout << "Enter Form name: ";
				std::getline(std::cin, fname);
				if (fname == "b")
					break;

				std::cout << "Enter grade required to sign: ";
				std::getline(std::cin, signGradeStr);
				if (signGradeStr == "b")
					break;

				std::cout << "Enter grade required to execute: ";
				std::getline(std::cin, execGradeStr);
				if (execGradeStr == "b")
					break;

				try {
					signGrade = my_stoi(signGradeStr);
					execGrade = my_stoi(execGradeStr);

					Form f(fname, signGrade, execGrade);
					std::cout << "\nCreated Form: " << f << std::endl;
					forms.push_back(f);

					while (true) {
						std::string choice;

						std::cout << "\n=== Bureaucrat Menu ===\n";
						std::cout << "[p] Promote Bureaucrat\n";
						std::cout << "[d] Demote Bureaucrat\n";
						std::cout << "[s] Sign a form\n";
						std::cout << "[b] Go back to form creation\n";
						std::cout << "[quit] Quit program\n";
						std::cout << "Enter choice: ";

						std::getline(std::cin, choice);

						if (choice == "quit")
							return 0;
						else if (choice == "b")
							break;
						else if (choice == "p") {
							try {
								std::cout << "Promoting " << b.getName() << std::endl;
								b.incrementGrade();
								std::cout << "Now: " << b << std::endl;
							} catch (const std::exception& e) {
								std::cerr << "Error: " << e.what() << std::endl;
							}
						}
						else if (choice == "d") {
							try {
								std::cout << "Demoting " << b.getName() << std::endl;
								b.decrementGrade();
								std::cout << "Now: " << b << std::endl;
							} catch (const std::exception& e) {
								std::cerr << "Error: " << e.what() << std::endl;
							}
						}
						else if (choice == "s") {
							std::cout << "\n=== List of Forms ===\n";
							for (size_t i = 0; i < forms.size(); ++i) {
								std::cout << "[" << (i + 1) << "] " << forms[i] << std::endl;
							}
							if (forms.empty()) {
								std::cout << "No forms available to sign.\n";
								continue;
							}
							std::string indexStr;
							std::cout << "Enter form index to sign: ";
							std::getline(std::cin, indexStr);
							try {
								int idx = my_stoi(indexStr) - 1;
								if (idx < 0 || static_cast<size_t>(idx) >= forms.size()) {
									std::cout << "Invalid index.\n";
								} else {
									b.signForm(forms[idx]);
									std::cout << "Updated Form: " << forms[idx] << std::endl;
								}
							} catch (...) {
								std::cout << "Invalid input.\n";
							}
						}
						else {
							std::cout << "Invalid input. Use 'p', 'd', 's', 'b', or 'quit'.\n";
						}
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Error creating form: " << e.what() << std::endl;
				}
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
			std::cout << "Please try again.\n";
		}
	}

	std::cout << "\nExiting program. Goodbye.\n";
	return 0;
}
