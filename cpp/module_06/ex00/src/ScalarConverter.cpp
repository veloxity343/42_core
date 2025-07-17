#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

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
	if (lit[i] == '-' || lit[i] == '+')
		++i;
	bool has_digit = false;

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
	return (dot_count == 1 && has_digit);
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

void ScalarConverter::toChar(const std::string& lit) {
	char c = lit[0];
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(SCALAR_PRECISION)
			  << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::toInt(const std::string& lit) {
	long i = std::atol(lit.c_str());

	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(SCALAR_PRECISION)
			  << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::toFloat(const std::string& lit) {
	float f = std::strtof(lit.c_str(), NULL);

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (f < 32 || f == 127)
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

	std::cout << "int: ";
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(SCALAR_PRECISION)
			  << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::toDouble(const std::string& lit) {
	double d = std::atof(lit.c_str());

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (d < 32 || d == 127)
		std::cout << "Non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

	std::cout << "int: ";
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(SCALAR_PRECISION)
			  << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
