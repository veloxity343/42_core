#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../inc/Span.hpp"

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	try {
		std::cout << "=== Test 1: Basic usage ===\n";
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
		std::cout << "Longest span: " << sp.longestSpan() << '\n';

		std::cout << "\n=== Test 2: Overfilling ===\n";
		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	try {
		std::cout << "\n=== Test 3: Not enough elements ===\n";
		Span sp2(2);
		sp2.addNumber(5);
		// sp2.addNumber(10);
		std::cout << "Attempting shortest span...\n";
		std::cout << "Shortest span: " << sp2.shortestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	try {
		std::cout << "\n=== Test 4: Bulk range add ===\n";
		unsigned int N = 10000;
		Span bigSpan(N);
		std::vector<int> nums;
		for (unsigned int i = 0; i < N; ++i)
			nums.push_back(std::rand());

		bigSpan.addRange(nums.begin(), nums.end());

		std::cout << "Shortest span: " << bigSpan.shortestSpan() << '\n';
		std::cout << "Longest span: " << bigSpan.longestSpan() << '\n';
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	try {
		std::cout << "\n=== Test 5: Range too large ===\n";
		Span sp3(3);
		std::vector<int> few;
		few.push_back(1);
		few.push_back(2);
		few.push_back(3);
		few.push_back(4);
		sp3.addRange(few.begin(), few.end());
	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	return 0;
}
