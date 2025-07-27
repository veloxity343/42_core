#include <iostream>
#include <list>
#include <limits>
#include "../inc/MutantStack.hpp"

// void testMutantStack() {
// 	std::cout << "MutantStack Test" << std::endl;
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << "Top: " << mstack.top() << "" << std::endl;
// 	std::cout << "Size: " << mstack.size() << "" << std::endl;
// 	mstack.pop();
// 	std::cout << "Size after pop: " << mstack.size() << "" << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
// 		std::cout << *it << "" << std::endl;
// }

// void testList() {
// 	std::cout << "std::list Test" << std::endl;
// 	std::list<int> lst;

// 	lst.push_back(5);
// 	lst.push_back(17);
// 	std::cout << "Back: " << lst.back() << "" << std::endl;
// 	std::cout << "Size: " << lst.size() << "" << std::endl;
// 	lst.pop_back();
// 	std::cout << "Size after pop: " << lst.size() << "" << std::endl;

// 	lst.push_back(3);
// 	lst.push_back(5);
// 	lst.push_back(737);
// 	lst.push_back(0);

// 	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
// 		std::cout << *it << "" << std::endl;
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
			  << "[0] Exit\n"
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
			std::cout << "Invalid input." << std::endl;
			continue;
		}

		switch (choice) {
			case 1:
				std::cout << "Enter value to push: ";
				std::cin >> value;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input." << std::endl;
					continue;
				}
				mstack.push(value);
				lst.push_back(value);
				std::cout << "Value pushed." << std::endl;
				break;

			case 2:
				if (!mstack.empty() && !lst.empty()) {
					mstack.pop();
					lst.pop_back();
					std::cout << "Top/back popped." << std::endl;
				} else {
					std::cout << "Both containers are empty." << std::endl;
				}
				break;

			case 3:
				if (!mstack.empty() && !lst.empty()) {
					std::cout << "MutantStack top:	" << mstack.top() << std::endl;
					std::cout << "List back:		" << lst.back() << std::endl;
				} else {
					std::cout << "Both containers are empty." << std::endl;
				}
				break;

			case 4:
				std::cout << "MutantStack size:	" << mstack.size() << std::endl;
				std::cout << "List size:		" << lst.size() << std::endl;
				break;

			case 5:
				printContainers(mstack, lst);
				break;

			case 0:
				std::cout << "Goodbye!" << std::endl;
				return 0;

			default:
				std::cout << "Invalid choice." << std::endl;
				break;
		}
	}
}
