#include <exception>
#include "../inc/PmergeMe.hpp"

std::string argjoin(int argc, char **argv) {
	std::string s;
	for (int i = 1; i < argc; i++) {
		s += argv[i];
		if (i != argc - 1)
			s += " ";
	}
	return s;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Invalid input! Usage: ./PmergeMe <elements of positive value>" << std::endl;
		return 1;
	}
	
	std::string s = argjoin(argc, argv);
	PmergeMe mi;

	try {
		mi.run(s);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
