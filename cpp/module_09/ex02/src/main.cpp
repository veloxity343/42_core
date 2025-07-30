#include <exception>
#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: Usage: " << argv[0] << " <positive integers>" << std::endl;
		return 1;
	}

	Str s;
	PmergeMe mi;

	for (int i = 1; i < argc; i++) {
		s += argv[i];
		if (i != argc - 1)
			s += " ";
	}

	try {
		mi.Run(s);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
