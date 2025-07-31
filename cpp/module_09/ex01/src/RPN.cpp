#include <list>
#include <sstream>
#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack), _token(other._token) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
		_token = other._token;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::Calculate(const std::string& input) {
	if (input.empty())
		throw std::runtime_error("Error: Empty expression");

	loadToken(input);

	if (_token.empty())
		throw std::runtime_error("Error: No valid tokens in expression");

	for (std::list<std::string>::iterator it = _token.begin(); it != _token.end(); ++it) {
		processToken(*it);
	}

	if (_stack.size() > 1)
		throw std::runtime_error("Error: Not enough operators for all numbers");
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid RPN syntax");

	std::cout << "(" << input << ") = " << _stack.front() << "." << std::endl;
}

void RPN::loadToken(const Str& input) {
	std::stringstream ss(input);
	Str tok;
	while (ss >> tok) {
		_token.push_back(tok);
	}
}

void RPN::processToken(const Str& token) {
	if (isOperator(token)) {
		if (_stack.size() < 2)
			throw std::runtime_error("Error: Not enough numbers for operator '" + token + "'");
		performOperation(token[0]);
	} else if (token.length() == 1 && std::ispunct(token[0])) {
		throw std::runtime_error("Error: Invalid operator '" + token + "'");
	} else if (!token.empty()) {
		_stack.push_front(toNumber(token));
	} else {
		throw std::runtime_error("Error: Empty token");
	}
}

bool RPN::isOperator(const Str& s) const {
	return s == "+" || s == "-" || s == "*" || s == "/";
}

rpn_l RPN::toNumber(const Str& token) const {
	std::stringstream ss(token);
	rpn_l num;
	char extra;
	if (!(ss >> num) || (ss >> extra))
		throw std::runtime_error("Error: Invalid number '" + token + "'");
	return num;
}

void RPN::performOperation(char op) {
	rpn_l b = _stack.front(); _stack.pop_front();
	rpn_l a = _stack.front(); _stack.pop_front();

	switch (op) {
		case '+':
			_stack.push_front(a + b);
			break;
		case '-':
			_stack.push_front(a - b);
			break;
		case '*':
			_stack.push_front(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			_stack.push_front(a / b);
			break;
		default:
			throw std::runtime_error("Error: Unknown operator");
	}
}
