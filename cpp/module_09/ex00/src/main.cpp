#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include "../inc/BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <path_to_csv>" << std::endl;
		return 1;
	}

	Str dbPath = "data.csv";

	BitcoinExchange btc;
	(void)argv;
	try {
		btc.loadDB(dbPath);
		// btc.printDB();
		btc.checkInput(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
