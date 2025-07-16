#include "ScalarConverter.hpp"

int main() {
	std::string input;

	std::cout << "Enter a string literal to convert (type \"exit\" to quit)" << std::endl;

	while (true) {
		std::cout << "\n> ";
		std::getline(std::cin, input);

		if (std::cin.eof() || input == "exit")
			break;

		try {
			ScalarConverter converter(input);
		}
		catch (const ScalarConverter::ErrorException& e) {
			std::cerr << "Conversion error: " << e.what() << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Unexpected error: " << e.what() << std::endl;
		}
	}

	std::cout << "Exiting ScalarConverter. Goodbye!" << std::endl;
	return 0;
}
