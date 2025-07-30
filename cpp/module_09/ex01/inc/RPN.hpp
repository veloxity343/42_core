#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <list>

typedef std::string Str;
typedef long rpn_l;

class RPN {
private:
	std::list<rpn_l> _stack;
	std::list<Str> _token;

	void loadToken(const Str& input);
	void processToken(const Str& token);
	bool isOperator(const Str& token) const;
	rpn_l toNumber(const Str& token) const;
	void performOperation(char op);

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void Calculate(const Str& input);
};

#endif
