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
			ScalarConverter::Convert(input);
		}
		catch (const std::exception& e) {
			std::cerr << "Conversion error: " << e.what() << std::endl;
		}
	}
	std::cout << "\nExiting converter. Goodbye!" << std::endl;
	return 0;
}
