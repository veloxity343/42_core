#include <vector>
#include <list>
#include <deque>
#include "../inc/easyfind.hpp"

int main()
{
	std::cout << "\033[1;36m\n-----------------------\n\033[0m";
	std::cout << "\033[1;36m\nExecuting Test for ex00\n\033[0m";
	std::cout << "\033[1;36m\n-----------------------\n\033[0m";

	std::cout << "\033[33m\nTest for vector container (elements 0 - 9)\n\033[0m";

	std::vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	std::cout << "\033[34m\nFinding 5 within container\n\033[0m";

	try {
		std::cout << *easyfind(v, 5) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[34m\nFinding 20 within container\n\033[0m";

	try {
		std::cout << *easyfind(v, 20) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "\033[33m\nTest for list container (elements 0 - 9)\n\033[0m";
	
	std::list<int> l;

	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}

	std::cout << "\033[34m\nFinding 5 within container\n\033[0m";

	try {
		std::cout << *easyfind(l, 0) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[34m\nFinding 20 within container\n\033[0m";

	try {
		std::cout << *easyfind(l, 20) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m\nTest for deque container (elements 0 - 9)\n\033[0m";

	std::deque<int> d;

	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}

	std::cout << "\033[34m\nFinding 5 within container\n\033[0m";

	try {
		std::cout << *easyfind(d, 5) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[34m\nFinding 20 within container\n\033[0m";

	try {
		std::cout << *easyfind(d, 20) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
