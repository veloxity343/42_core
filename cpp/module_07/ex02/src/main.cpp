#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> a(5);
		for (std::size_t i = 0; i < a.size(); ++i)
			a[i] = static_cast<int>(i) * 10;

		std::cout << "Original array:\n";
		for (std::size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << "\n";

		Array<int> b = a;
		b[0] = 999;

		std::cout << "Modified copy:\n";
		for (std::size_t i = 0; i < b.size(); ++i)
			std::cout << b[i] << " ";
		std::cout << "\n";

		std::cout << "Original array (should be unchanged):\n";
		for (std::size_t i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << "\n";

		std::cout << "Accessing out of bounds:\n";
		std::cout << a[100] << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
}
