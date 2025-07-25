#include <iostream>
#include <list>
#include <limits>
#include "../inc/MutantStack.hpp"

// void testMutantStack() {
// 	std::cout << "MutantStack Test\n";
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << "Top: " << mstack.top() << "\n";
// 	std::cout << "Size: " << mstack.size() << "\n";
// 	mstack.pop();
// 	std::cout << "Size after pop: " << mstack.size() << "\n";

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
// 		std::cout << *it << "\n";
// }

// void testList() {
// 	std::cout << "std::list Test\n";
// 	std::list<int> lst;

// 	lst.push_back(5);
// 	lst.push_back(17);
// 	std::cout << "Back: " << lst.back() << "\n";
// 	std::cout << "Size: " << lst.size() << "\n";
// 	lst.pop_back();
// 	std::cout << "Size after pop: " << lst.size() << "\n";

// 	lst.push_back(3);
// 	lst.push_back(5);
// 	lst.push_back(737);
// 	lst.push_back(0);

// 	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
// 		std::cout << *it << "\n";
// }

// int main() {
// 	testMutantStack();
// 	std::cout << std::endl;
// 	testList();
// 	return 0;
// }

void printMenu() {
	std::cout << "\nMenu\n"
			  << "[1] Push value\n"
			  << "[2] Pop value\n"
			  << "[3] View top/back\n"
			  << "[4] View size\n"
			  << "[5] Print all elements\n"
			  << "[6] Exit\n"
			  << "Enter choice: ";
}

void printContainers(const MutantStack<int>& mstack, const std::list<int>& lst) {
	std::cout << "\nMutantStack contents:	";
	for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\nList contents:		";
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main() {
	MutantStack<int> mstack;
	std::list<int> lst;

	int choice, value;

	while (true) {
		printMenu();
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.\n";
			continue;
		}

		switch (choice) {
			case 1:
				std::cout << "Enter value to push: ";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input.\n";
					continue;
				}
				mstack.push(value);
				lst.push_back(value);
				std::cout << "Value pushed.\n";
				break;

			case 2:
				if (!mstack.empty() && !lst.empty()) {
					mstack.pop();
					lst.pop_back();
					std::cout << "Top/back popped.\n";
				} else {
					std::cout << "Both containers are empty.\n";
				}
				break;

			case 3:
				if (!mstack.empty() && !lst.empty()) {
					std::cout << "MutantStack top:	" << mstack.top() << std::endl;
					std::cout << "List back:		" << lst.back() << std::endl;
				} else {
					std::cout << "Both containers are empty.\n";
				}
				break;

			case 4:
				std::cout << "MutantStack size:	" << mstack.size() << std::endl;
				std::cout << "List size:		" << lst.size() << std::endl;
				break;

			case 5:
				printContainers(mstack, lst);
				break;

			case 6:
				std::cout << "Goodbye!\n";
				return 0;

			default:
				std::cout << "Invalid choice.\n";
				break;
		}
	}
}
