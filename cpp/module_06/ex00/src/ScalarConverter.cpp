#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& lit) {
	if (isPseudoLit(lit))
		return;

	try {
		if (isChar(lit))
			toChar(lit);
		else if (isInt(lit))
			toInt(lit);
		else if (isFloat(lit))
			toFloat(lit);
		else if (isDouble(lit))
			toDouble(lit);
		else
			throw std::invalid_argument("Unknown literal type: \"" + lit + "\"");
	} catch (const std::exception& e) {
		std::cerr << "Conversion error: " << e.what() << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& lit) {
	return (lit.length() == 1 && std::isprint(lit[0]) && !std::isdigit(lit[0]));
}

bool ScalarConverter::isInt(const std::string& lit) {
	size_t i = 0;
	if (lit[i] == '-' || lit[i] == '+')
		++i;
	if (i == lit.length()) return false;

	while (i < lit.length()) {
		if (!std::isdigit(lit[i]))
			return false;
		++i;
	}
	long val = std::atol(lit.c_str());
	return (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string& lit) {
	size_t i = 0, dot_count = 0;
	if (lit[i] == '-' || lit[i] == '+')
		++i;
	bool has_digit = false;

	while (i < lit.length()) {
		if (std::isdigit(lit[i])) {
			has_digit = true;
		} else if (lit[i] == '.') {
			if (++dot_count > 1)
				return false;
		} else if ((lit[i] == 'f' || lit[i] == 'F') && i == lit.length() - 1 && dot_count == 1) {
			return has_digit;
		} else {
			return false;
		}
		++i;
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string& lit) {
	size_t i = 0, dot_count = 0;
	bool has_digit = false;

	if (lit[i] == '-' || lit[i] == '+')
		++i;

	while (i < lit.length()) {
		if (std::isdigit(lit[i])) {
			has_digit = true;
		} else if (lit[i] == '.') {
			if (++dot_count > 1)
				return false;
		} else {
			return false;
		}
		++i;
	}
	return (has_digit);
}

bool ScalarConverter::isPseudoLit(const std::string& lit) {
	std::string charMsg = "char: impossible";
	std::string intMsg = "int: impossible";

	if (lit == "nanf" || lit == "nan") {
		std::cout << charMsg << "\n" << intMsg << "\n"
				  << "float: nanf\n" << "double: nan" << std::endl;
		return true;
	}
	if (lit == "-inff" || lit == "-inf") {
		std::cout << charMsg << "\n" << intMsg << "\n"
				  << "float: -inff\n" << "double: -inf" << std::endl;
		return true;
	}
	if (lit == "+inff" || lit == "+inf" || lit == "inff" || lit == "inf") {
		std::cout << charMsg << "\n" << intMsg << "\n"
				  << "float: inff\n" << "double: inf" << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::toChar(const std::string& lit) {
	Print(static_cast<double>(lit[0]));
}

void ScalarConverter::toInt(const std::string& lit) {
	long i = std::atol(lit.c_str());
	Print(static_cast<double>(i));
}

void ScalarConverter::toFloat(const std::string& lit) {
	errno = 0;
	char* endptr = NULL;
	float f = std::strtof(lit.c_str(), &endptr);
	if (errno == ERANGE || std::isinf(f)) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return;
	}
	Print(static_cast<double>(f));
}

void ScalarConverter::toDouble(const std::string& lit) {
	errno = 0;
	char* endptr = NULL;
	double d = std::strtod(lit.c_str(), &endptr);
	if (errno == ERANGE || std::isinf(d)) {
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return;
	}
	Print(d);
}

void ScalarConverter::Print(double val) {
	std::cout << "char: ";
	if (std::isnan(val) || val < 0 || val > 127 || std::floor(val) != val)
		std::cout << "impossible" << std::endl;
	else if (val < 32 || val == 127)
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

	std::cout << "int: ";
	if (std::isnan(val) || val < INT_MIN || val > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(val) << std::endl;

	std::cout << "float: ";
	if (std::isnan(val) || std::isinf(val) || val < -FLT_MAX || val > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(SCALAR_PRECISION)
				  << static_cast<float>(val) << "f" << std::endl;

	std::cout << "double: " << std::fixed << std::setprecision(SCALAR_PRECISION)
			  << val << std::endl;
}
