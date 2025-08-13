#include <list>
#include <sstream>
#include "../inc/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _list(other._list), _token(other._token) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_list = other._list;
		_token = other._token;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::Calculate(const Str& input) {
	if (input.empty())
		throw std::runtime_error("Empty expression");

	loadToken(input);

	if (_token.empty())
		throw std::runtime_error("No valid tokens in expression");

	for (std::list<Str>::iterator it = _token.begin(); it != _token.end(); ++it) {
		processToken(*it);
	}

	if (_list.size() > 1)
		throw std::runtime_error("Not enough operators for all numbers");
	if (_list.size() != 1)
		throw std::runtime_error("Invalid RPN syntax");

	std::cout << "(" << input << ") = " << _list.back() << std::endl;
}

void RPN::loadToken(const Str& input) {
	_token.clear();
	std::stringstream ss(input);
	Str tok;

	while (ss >> tok) {
		_token.push_back(tok);
	}
}

void RPN::processToken(const Str& token) {
	if (isOperator(token)) {
		if (_list.size() < 2)
			throw std::runtime_error("Not enough numbers for operator '" + token + "'");
		performOperation(token[0]);
	} else if (token.length() == 1 && std::ispunct(token[0])) {
		throw std::runtime_error("Invalid operator '" + token + "'");
	} else if (!token.empty()) {
		_list.push_back(toNumber(token));
	} else {
		throw std::runtime_error("Empty token");
	}
}

bool RPN::isOperator(const Str& s) const {
	return (s == "+" || s == "-" || s == "*" || s == "/");
}

rpn_l RPN::toNumber(const Str& token) const {
	std::stringstream ss(token);
	rpn_l num;
	char extra;
	
	if (!(ss >> num) || (ss >> extra))
		throw std::runtime_error("Invalid number '" + token + "'");
	return num;
}

void RPN::performOperation(char op) {
	rpn_l b = _list.back();
	_list.pop_back();
	rpn_l a = _list.back();
	_list.pop_back();

	switch (op) {
		case '+':
			_list.push_back(a + b);
			break;
		case '-':
			_list.push_back(a - b);
			break;
		case '*':
			_list.push_back(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Division by zero");
			_list.push_back(a / b);
			break;
		default:
			throw std::runtime_error("Unknown operator");
	}
}
