#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string& input) : _input(input) {
	std::cout << "Parameterized Constructor for \"" << _input << "\"" << std::endl;
	this->detectType(_input);
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) : _input(src._input) {
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &src) {
		_input = src._input;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called for \"" << _input << "\"" << std::endl;
}

bool ScalarConverter::is_char(const std::string& literal) {
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::is_int(const std::string& literal) {
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		++i;
	if (i == literal.length()) return false;

	while (i < literal.length()) {
		if (!std::isdigit(literal[i]))
			return false;
		++i;
	}
	long val = std::atol(literal.c_str());
	return (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

bool ScalarConverter::is_float(const std::string& literal) {
	size_t i = 0, dot_count = 0;
	if (literal[i] == '-' || literal[i] == '+')
		++i;
	bool has_digit = false;

	while (i < literal.length()) {
		if (std::isdigit(literal[i])) {
			has_digit = true;
		} else if (literal[i] == '.') {
			if (++dot_count > 1)
				return false;
		} else if ((literal[i] == 'f' || literal[i] == 'F') && i == literal.length() - 1 && dot_count == 1) {
			return has_digit;
		} else {
			return false;
		}
		++i;
	}
	return false;
}

bool ScalarConverter::is_double(const std::string& literal) {
	size_t i = 0, dot_count = 0;
	if (literal[i] == '-' || literal[i] == '+')
		++i;
	bool has_digit = false;

	while (i < literal.length()) {
		if (std::isdigit(literal[i])) {
			has_digit = true;
		} else if (literal[i] == '.') {
			if (++dot_count > 1)
				return false;
		} else {
			return false;
		}
		++i;
	}
	return (dot_count == 1 && has_digit);
}

bool ScalarConverter::handle_pseudo_literals(const std::string& literal) {
	std::string charMsg = "char: impossible";
	std::string intMsg = "int: impossible";

	if (literal == "nanf" || literal == "nan") {
		std::cout << charMsg << "\n" << intMsg << "\n"
		          << "float: nanf\n" << "double: nan" << std::endl;
		return true;
	}
	if (literal == "-inff" || literal == "-inf") {
		std::cout << charMsg << "\n" << intMsg << "\n"
		          << "float: -inff\n" << "double: -inf" << std::endl;
		return true;
	}
	if (literal == "+inff" || literal == "+inf" || literal == "inff" || literal == "inf") {
		std::cout << charMsg << "\n" << intMsg << "\n"
		          << "float: inff\n" << "double: inf" << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::detectType(const std::string& literal) {
	if (handle_pseudo_literals(literal))
		return;
	else if (is_char(literal))
		literal_to_char(literal);
	else if (is_int(literal))
		literal_to_int(literal);
	else if (is_float(literal))
		literal_to_float(literal);
	else if (is_double(literal))
		literal_to_double(literal);
	else
		std::cout << "Unknown literal type" << std::endl;
}

void ScalarConverter::literal_to_char(const std::string& literal) {
	char c = literal[0];
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::literal_to_int(const std::string& literal) {
	long i = std::atol(literal.c_str());

	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::literal_to_float(const std::string& literal) {
	float f = std::strtof(literal.c_str(), NULL);

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (f < 32 || f == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

	std::cout << "int: ";
	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::literal_to_double(const std::string& literal) {
	double d = std::atof(literal.c_str());

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (d < 32 || d == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

	std::cout << "int: ";
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1)
	          << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
