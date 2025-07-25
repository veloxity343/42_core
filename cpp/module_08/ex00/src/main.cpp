#include <vector>
#include <list>
#include <deque>
#include <limits>
#include "../inc/easyfind.hpp"


void printMenu() {
	std::cout << "\nContainer selection" << std::endl;
	std::cout << "[1] Vector" << std::endl;
	std::cout << "[2] List" << std::endl;
	std::cout << "[3] Deque" << std::endl;
	std::cout << "[0] Exit" << std::endl;
	std::cout << "Select a container type: ";
}

int getInput(const std::string &prompt) {
	int val;
	while (true) {
		std::cout << prompt;
		if (std::cin >> val)
			return val;
		std::cout << "Invalid input. Please enter an integer." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

template <typename T>
void runContainerTest(const std::string &containerName) {
	int size = getInput("Enter number of elements: ");
	if (size < 0) {
		std::cout << "Size cannot be negative. Returning to menu." << std::endl;
		return;
	}

	T container;
	for (int i = 1; i <= size; ++i)
		container.push_back(i);

	std::cout << containerName << " contents: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	while (true) {
		std::cout << "\nEasyfind" << std::endl;
		std::cout << "[1] Find a number" << std::endl;
		std::cout << "[0] Back to main menu" << std::endl;

		int choice = getInput("Select an option: ");
		switch (choice) {
			case 0:
				return;
			case 1: {
				int target = getInput("Enter number to find: ");
				try {
					typename T::iterator found = easyfind(container, target);
					std::cout << "Found: " << *found << '\n';
				} catch (const std::exception &e) {
					std::cout << e.what() << '\n';
				}
				break;
			}
			default:
				std::cout << "Invalid option. Try again." << std::endl;
				break;
		}
	}
}

int main() {
	while (true) {
		printMenu();
		int choice = getInput("");
		switch (choice) {
			case 1: {
				runContainerTest<std::vector<int> >("Vector");
				break;
			}
			case 2: {
				runContainerTest<std::list<int> >("List");
				break;
			}
			case 3: {
				runContainerTest<std::deque<int> >("Deque");
				break;
			}
			case 0: {
				std::cout << "Goodbye!" << std::endl;
				return 0;
			}
			default:
				std::cout << "Invalid option. Try again." << std::endl;
				continue;
		}
	}
}
