#include <iostream>
#include "../inc/whatever.hpp"

int main() {
	int a = 2;
	int b = 3;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string x = "chaine1";
	std::string y = "chaine2";

	std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;

	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	return 0;
}
