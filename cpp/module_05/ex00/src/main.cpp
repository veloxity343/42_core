#include "../inc/Bureaucrat.hpp"
#include <sstream>

int ft_stoi(const std::string& s) {
	std::istringstream iss(s);
	int result;
	char leftover;

	if (!(iss >> result) || (iss >> leftover)) {
		throw std::invalid_argument("Invalid input for integer conversion");
	}
	return result;
}

int main() {
	while (true) {
		std::string name;
		std::string gradeInput;
		int grade;

		std::cout << "\n=== Create a Bureaucrat ===\n";
		std::cout << "Type 'quit' to exit" << std::endl;
		std::cout << "Enter Bureaucrat name: ";
		std::getline(std::cin, name);
		if (name == "quit")
			break;
		
		std::cout << "Type 'quit' to exit" << std::endl;
		std::cout << "Enter Bureaucrat grade (1-150): ";
		std::getline(std::cin, gradeInput);
		if (gradeInput == "quit")
			break;

		try {
			grade = ft_stoi(gradeInput);
			Bureaucrat b(name, grade);
			std::cout << "Created: " << b << std::endl;

			while (true) {
				std::string choice;
				std::cout << "\nWould you like to increment, decrement, or quit? (i/d/quit): ";
				std::getline(std::cin, choice);

				try {
					if (choice == "i") {
						std::cout << "Promoting " << b.getName() << std::endl;
						b.incrementGrade();
						std::cout << "Now: " << b << std::endl;
					}
					else if (choice == "d") {
						std::cout << "Demoting " << b.getName() << std::endl;
						b.decrementGrade();
						std::cout << "Now: " << b << std::endl;
					}
					else if (choice == "quit") {
						break;
					}
					else {
						std::cout << "Invalid input. Type 'i', 'd', or 'quit'." << std::endl;
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Exception during grade update: " << e.what() << std::endl;
				}
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			std::cout << "Please try creating the Bureaucrat again.\n";
		}
	}
	return 0;
}
