#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>

typedef std::string Str;

class BitcoinExchange {
private:
	std::map<Str, double> _db;

	bool isValidDate(const Str& s) const;
	bool parseLine(const Str& line, const Str& delim,
				   Str& dateOut, Str& valueStrOut) const;
	bool validEntry(const Str& date, const Str& valueStr,
							std::pair<Str, double>& out, double maxValue) const;
	void printError(const Str& msg, const Str& context) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDB(const Str& path);
	void checkInput(const Str& path);
	bool parseToPair(std::pair<Str, double>& p, const Str& line,
							const Str& delim, double maxValue);
	void matchDB(const std::pair<Str, double>& p) const;
	void printDB() const;
};

#endif
