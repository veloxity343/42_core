#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> _db;

	bool isValidDate(const std::string& s) const;
	bool parseLine(const std::string& line, const std::string& delim,
				   std::string& dateOut, std::string& valueStrOut) const;
	bool validEntry(const std::string& date, const std::string& valueStr,
							std::pair<std::string, double>& out) const;
	void printError(const std::string& msg, const std::string& context) const;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	
	void loadDB(const std::string& path);
	void checkInput(const std::string& path);
	void printDB() const;
	bool parseToPair(std::pair<std::string, double>& p, const std::string& line, const std::string& delim);
	void matchDB(const std::pair<std::string, double>& p) const;
};

#endif
