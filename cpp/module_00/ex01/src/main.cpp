#include "PhoneBook.hpp"
#include <unistd.h>

int	main(void)
{
	std::string	input;
	PhoneBook phonebook;

	display_welcome();
	while (1)
	{
		system("clear");
		display_menu_and_prompt(input);
		if (input.empty())
			continue ;
		else if (input == "EXIT")
			return (system("clear"), 0);
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
		{
			std::cout << "Error: Please try a valid command." << std::endl;
			sleep(2);
		}
	}
	return (0);
}
