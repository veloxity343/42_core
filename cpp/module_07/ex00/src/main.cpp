#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../inc/whatever.hpp"

#define FLT_PREC 1

// int main() {
// 	int a = 2;
// 	int b = 3;

// 	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
// 	::swap(a, b);
// 	std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

// 	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

// 	std::string x = "chaine1";
// 	std::string y = "chaine2";

// 	std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
// 	::swap(x, y);
// 	std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;

// 	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
// 	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

// 	return 0;
// }

template <typename T>
void handleInput(const std::string& typeName) {
	std::string line;
	std::cout << "Enter two " << typeName << "s: ";
	std::getline(std::cin, line);

	std::istringstream iss(line);
	T a, b;
	std::string extra;

	if (!(iss >> a >> b) || (iss >> extra)) {
		std::cout << "Invalid input. Please enter exactly two " << typeName << "s.\n";
		return;
	}

	if (typeName == "float") {
		std::cout << std::fixed << std::setprecision(FLT_PREC);
	}

	std::cout << "Before swap: a = " << a << ", b = " << b << '\n';
	::swap(a, b);
	std::cout << "After swap:  a = " << a << ", b = " << b << '\n';
	std::cout << "Min: " << ::min(a, b) << '\n';
	std::cout << "Max: " << ::max(a, b) << '\n';
}

int main() {
	while (true) {
		std::cout << "\nMain Menu\n"
		          << "[1] int\n"
		          << "[2] float\n"
		          << "[3] char\n"
		          << "[4] string\n"
		          << "[0] Exit\n"
		          << "Choose an option: ";

		int choice;
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Invalid input. Try again.\n";
			continue;
		}

		std::cin.ignore(10000, '\n');

		switch (choice) {
			case 0:
				std::cout << "Goodbye!\n";
				return 0;
			case 1:
				handleInput<int>("int");
				break;
			case 2:
				handleInput<float>("float");
				break;
			case 3:
				handleInput<char>("char");
				break;
			case 4:
				handleInput<std::string>("string");
				break;
			default:
				std::cout << "Invalid option. Try again.\n";
		}
	}
}
