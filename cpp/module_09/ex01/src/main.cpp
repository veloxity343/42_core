#include "../inc/RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Invalid input! Usage: <./RPN \"1 2 + 3 +\">" << std::endl;
		return 1;
	}
	
	RPN rpn;

	try {
		std::cout << "===RPN===\n";
		rpn.calculate(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
