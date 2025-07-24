#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }

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
