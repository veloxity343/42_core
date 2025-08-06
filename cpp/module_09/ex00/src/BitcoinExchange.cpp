#include <fstream>
#include <sstream>
#include <ctime>
#include <exception>
#include <string>
#include <utility>
#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_db = other._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDB(const Str& path) {
	std::ifstream inFile(path.c_str());
	if (!inFile)
		throw std::runtime_error("Could not open csv file");

	if (inFile.peek() == std::ifstream::traits_type::eof()) {
		throw std::runtime_error("CSV file is empty");
	}

	Str line;
	std::getline(inFile, line);

	if (inFile.peek() == std::ifstream::traits_type::eof()) {
		throw std::runtime_error("CSV file contains no data");
	}
	
	std::pair<Str, double> entry;

	while (std::getline(inFile, line)) {
		if (!parseToPair(entry, line, ",", 2147483647.0))
			continue;
		_db[entry.first] = entry.second;
	}
}

void BitcoinExchange::checkInput(const Str& path) {
	std::ifstream inFile(path.c_str());
	if (!inFile)
		throw std::runtime_error("Failed to open input file");

	if (inFile.peek() == std::ifstream::traits_type::eof()) {
		printError("Input file is empty", "");
		return;
	}

	Str line;
	std::getline(inFile, line);

	if (inFile.peek() == std::ifstream::traits_type::eof()) {
		printError("Input file contains no data", "");
		return;
	}

	std::pair<Str, double> entry;

	while (std::getline(inFile, line)) {
		if (!parseToPair(entry, line, "|", 1000.0))
			continue;
		matchDB(entry);
	}
}

void BitcoinExchange::matchDB(const std::pair<Str, double>& entry) const {
	std::map<Str, double>::const_iterator it = _db.lower_bound(entry.first);

	if (it != _db.end() && it->first == entry.first) {
		std::cout << entry.first << " => " << entry.second
				  << " = " << entry.second * it->second << std::endl;
	}
	else if (it != _db.begin()) {
		--it;
		std::cout << entry.first << " => " << entry.second
				  << " = " << entry.second * it->second << std::endl;
	}
	else {
		printError("No earlier date found", entry.first);
	}
}

bool BitcoinExchange::parseToPair(std::pair<Str, double>& entry,
								  const Str& line, const Str& delim, double maxValue) {
	Str date, valueStr;
	if (!parseLine(line, delim, date, valueStr))
		return false;
	return validEntry(date, valueStr, entry, maxValue);
}

bool BitcoinExchange::parseLine(const Str& line, const Str& delim,
								Str& dateOut, Str& valueStrOut) const {
	if (delim.empty()) {
		printError("Missing delimiter", line);
		return false;
	}
	std::stringstream ss(line);
	if (!std::getline(ss, dateOut, delim[0]) || !std::getline(ss, valueStrOut)) {
		printError("Bad input", line);
		return false;
	}
	return true;
}

bool BitcoinExchange::validEntry(const Str& date, const Str& valueStr,
								 std::pair<Str, double>& out, double maxValue) const {
	if (!isValidDate(date)) {
		printError("Invalid date", date);
		return false;
	}

	if (valueStr.empty()) {
		printError("Empty float", date);
		return false;
	}

	std::stringstream ss(valueStr);
	double value;
	ss >> value;

	if (ss.fail() || !ss.eof()) {
		printError("Invalid float", valueStr);
		return false;
	}

	if (value < 0.0) {
		printError("Not a positive number", valueStr);
		return false;
	}

	if (value > maxValue) {
		printError("Too large a number", valueStr);
		return false;
	}

	out = std::make_pair(date, value);
	return true;
}

bool BitcoinExchange::isValidDate(const Str& dateStr) const {
	int y, m, d;
	char dash1, dash2;

	std::istringstream iss(dateStr);
	if (!(iss >> y >> dash1 >> m >> dash2 >> d) ||
		dash1 != '-' || dash2 != '-')
		return false;

	if (y < 1900 || y > 3000)
		return false;

	std::tm timeinfo = {};
	timeinfo.tm_year = y - 1900;
	timeinfo.tm_mon = m - 1;
	timeinfo.tm_mday = d;

	std::time_t t = std::mktime(&timeinfo);
	if (t == -1)
		return false;

	return timeinfo.tm_year == y - 1900 &&
		   timeinfo.tm_mon == m - 1 &&
		   timeinfo.tm_mday == d;
}

void BitcoinExchange::printError(const Str& msg, const Str& context) const {
	std::cerr << "\033[1;31mError: \033[0m" << msg;
	if (!context.empty())
		std::cerr << " => " << context;
	std::cerr << std::endl;
}

void BitcoinExchange::printDB() const {
	std::map<Str, double>::const_iterator it = _db.begin();
	std::size_t i = 0;
	for (; it != _db.end(); ++it, ++i) {
		std::cout << i << ". [" << it->first << "]: '" << it->second << "'" << std::endl;
	}
}
