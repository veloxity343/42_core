#include "../inc/RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}
	
	RPN rpn;

	try {
		rpn.Calculate(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
