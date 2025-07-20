#include <vector>
#include <list>
#include <deque>
#include <limits>
#include "../inc/easyfind.hpp"


void printMenu() {
	std::cout << "\n=== Container Selection Menu ===\n";
	std::cout << "[1] Vector\n";
	std::cout << "[2] List\n";
	std::cout << "[3] Deque\n";
	std::cout << "[0] Exit\n";
	std::cout << "Select a container type: ";
}

int getInput(const std::string &prompt) {
	int val;
	while (true) {
		std::cout << prompt;
		if (std::cin >> val)
			return val;
		std::cout << "Invalid input. Please enter an integer.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

template <typename T>
void runContainerTest(const std::string &containerName) {
	int size = getInput("Enter number of elements: ");
	if (size < 0) {
		std::cout << "Size cannot be negative. Returning to menu.\n";
		return;
	}

	T container;
	for (int i = 0; i < size; ++i)
		container.push_back(i);

	std::cout << containerName << " contents: ";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	while (true) {
		std::cout << "\n=== Easyfind Menu ===\n";
		std::cout << "[1] Find a number\n";
		std::cout << "[0] Back to main menu\n";

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
				std::cout << "Invalid option. Try again.\n";
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
				std::cout << "Goodbye!\n";
				return 0;
			}
			default:
				std::cout << "Invalid option. Try again.\n";
				continue;
		}
	}
}
