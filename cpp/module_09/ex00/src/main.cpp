#include <cmath>
#include <exception>
#include <fstream>
#include <string>
#include "../inc/BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "\033[1;31mError: \033[0mUsage: " << argv[0] << " <file.txt>" << std::endl;
		return 1;
	}

	Str dbPath = "data.csv";

	BitcoinExchange btc;
	(void)argv;
	try {
		btc.loadDB(dbPath);
		btc.checkInput(argv[1]);
		// btc.printDB();
	}
	catch (const std::exception& e) {
		std::cerr << "\033[1;31mError: \033[0m" << e.what() << std::endl;
	}

	return 0;
}
