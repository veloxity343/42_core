#pragma once

#include <iostream>
#include <string>
#include <cerrno>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>

#define SCALAR_PRECISION 1

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	static bool isChar(const std::string& lit);
	static bool isInt(const std::string& lit);
	static bool isFloat(const std::string& lit);
	static bool isDouble(const std::string& lit);
	static bool isPseudoLit(const std::string& lit);

	static void toChar(const std::string& literal);
	static void toInt(const std::string& literal);
	static void toFloat(const std::string& literal);
	static void toDouble(const std::string& literal);

	static void Print(double val);

public:
	static void convert(const std::string& lit);
};
