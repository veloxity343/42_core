#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <utility>
#include "../inc/BitcoinExchange.hpp"

static const int MIN_YEAR = 1900;
static const int MAX_YEAR = 3000;
static const double MAX_VALUE = 2147483647.0;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_db = other._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDB(const std::string& path) {
	std::ifstream inFile(path.c_str());
	if (!inFile)
		throw std::runtime_error("Error: Failed to open csv file");

	std::string line;
	std::getline(inFile, line);
	std::pair<std::string, double> entry;

	while (std::getline(inFile, line)) {
		if (!parseToPair(entry, line, ","))
			continue;
		_db[entry.first] = entry.second;
	}
}

bool BitcoinExchange::parseToPair(std::pair<std::string, double>& entry,
								  const std::string& line, const std::string& delim) {
	std::string date, valueStr;
	if (!parseLine(line, delim, date, valueStr))
		return false;
	return validEntry(date, valueStr, entry);
}

bool BitcoinExchange::parseLine(const std::string& line, const std::string& delim,
								std::string& dateOut, std::string& valueStrOut) const {
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

bool BitcoinExchange::validEntry(const std::string& date, const std::string& valueStr,
								 std::pair<std::string, double>& out) const {
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

	if (value > MAX_VALUE) {
		printError("Too large a number", valueStr);
		return false;
	}

	out = std::make_pair(date, value);
	return true;
}

bool BitcoinExchange::isValidDate(const std::string& dateStr) const {
	const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30,
							   31, 31, 30, 31, 30, 31};

	std::string sy, sm, sd;
	std::stringstream ss(dateStr);
	if (!std::getline(ss, sy, '-') || !std::getline(ss, sm, '-') || !std::getline(ss, sd))
		return false;

	int y, m, d;
	std::stringstream yss(sy), mss(sm), dss(sd);
	yss >> y;
	mss >> m;
	dss >> d;

	char c;
	if (yss.fail() || yss >> c || mss.fail() || mss >> c || dss.fail() || dss >> c)
		return false;

	if (y < MIN_YEAR || y > MAX_YEAR || m < 1 || m > 12)
		return false;

	int maxDay = daysInMonth[m];
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		maxDay = 29;

	if (d < 1 || d > maxDay)
		return false;

	return true;
}

void BitcoinExchange::checkInput(const std::string& path) {
	std::ifstream inFile(path.c_str());
	if (!inFile)
		throw std::runtime_error("Error: Failed to open input file");

	std::string line;
	std::getline(inFile, line);
	std::pair<std::string, double> entry;

	while (std::getline(inFile, line)) {
		if (!parseToPair(entry, line, "|"))
			continue;
		matchDB(entry);
	}
}

void BitcoinExchange::matchDB(const std::pair<std::string, double>& entry) const {
	std::map<std::string, double>::const_iterator it = _db.lower_bound(entry.first);

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

void BitcoinExchange::printDB() const {
	std::map<std::string, double>::const_iterator it = _db.begin();
	std::size_t i = 0;
	for (; it != _db.end(); ++it, ++i) {
		std::cout << i << ". [" << it->first << "]: '" << it->second << "'" << std::endl;
	}
}

void BitcoinExchange::printError(const std::string& msg, const std::string& context) const {
	std::cerr << "Error: " << msg;
	if (!context.empty())
		std::cerr << " => " << context;
	std::cerr << std::endl;
}
