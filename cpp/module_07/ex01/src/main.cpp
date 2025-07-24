#include <iostream>
#include "iter.hpp"

template<typename T>
void print(const T& value) {
	std::cout << value << std::endl;
}

template<typename T>
void doubleValue(T& value) {
	value *= 2;
}

void toUpper(char& c) {
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main() {
	std::cout << "Integer Test" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	::iter(intArr, 5, print<int>);
	std::cout << std::endl;
	::iter(intArr, 5, doubleValue<int>);
	::iter(intArr, 5, print<int>);

	std::cout << "\nString Test" << std::endl;
	std::string strArr[] = {"apple", "banana", "cherry"};
	::iter(strArr, 3, print<std::string>);

	std::cout << "\nChar Test" << std::endl;
	char charArr[] = {'a', 'b', 'c', 'd'};
    ::iter(charArr, 4, print<char>);
	std::cout << std::endl;
	::iter(charArr, 4, toUpper);
	::iter(charArr, 4, print<char>);

	return 0;
}
