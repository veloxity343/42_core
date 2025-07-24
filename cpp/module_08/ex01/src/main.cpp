#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../inc/Span.hpp"

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		sp.addNumber(42);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Span sp2(2);
		sp2.addNumber(5);
		// sp2.addNumber(10);
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		unsigned int N = 10000;
		Span bigSpan(N);
		std::vector<int> nums;
		for (unsigned int i = 0; i < N; ++i)
			nums.push_back(std::rand());

		bigSpan.addRange(nums.begin(), nums.end());

		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Span sp3(3);
		std::deque<int> few;
		few.push_back(1);
		few.push_back(2);
		few.push_back(3);
		few.push_back(4);
		sp3.addRange(few.begin(), few.end());
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
