#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>

class ScalarConverter {
private:
	std::string _input;

public:
	ScalarConverter();
	ScalarConverter(const std::string& input);
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);
	~ScalarConverter();

	void detectType(const std::string& literal);

private:
	bool is_char(const std::string& literal);
	bool is_int(const std::string& literal);
	bool is_float(const std::string& literal);
	bool is_double(const std::string& literal);
	bool handle_pseudo_literals(const std::string& literal);

	void literal_to_char(const std::string& literal);
	void literal_to_int(const std::string& literal);
	void literal_to_float(const std::string& literal);
	void literal_to_double(const std::string& literal);

    public:
        class ErrorException : public std::exception {
        private:
            std::string _message;
        public:
            ErrorException(const std::string& message) : _message(message) {}
            virtual ~ErrorException() throw() {}
            virtual const char* what() const throw() {
                return _message.c_str();
            }
        };
};
