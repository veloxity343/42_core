/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:07 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/22 17:02:47 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Constructor for PhoneBook class
 * @details Initializes the index to 0
 */
PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return ;
}

/**
 * @brief Destructor for PhoneBook class
 * @details Returns
 */
PhoneBook::~PhoneBook(void)
{
	return ;
}

/**
 * @brief Add a new contact to the phonebook
 * @details If contact exceeds 8, it overwrites first contact
 */
void	PhoneBook::add_contact(void)
{
	std::string	input;
	Contact	t_contact;

	system("clear");
	if (set_contact_details(t_contact) == false)
		return ;
	_contact_array[this->_index] = t_contact;
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
	std::cout << "Contact added successfully" << std::endl << std::endl;
	wait_for_enter();
}

/**
 * @brief Search for a contact in the phonebook
 * @details Displays contact details if found, else reprompts
 */
void	PhoneBook::search_contact(void)
{
	std::string	input;
	size_t		index;

	system("clear");
	while (1)
	{
		display_contact_table();
		std::cout << "Enter BACK to return to the Main Menu." << std::endl;
		std::cout << "Enter EXIT to exit the Phonebook." << std::endl << std::endl;
		get_input("Enter index to display contact [1 - 8]: ", input);
		index = input[0] - '0' - 1;
		system("clear");
		if (input == "BACK")
			return ;
		else if (input == "EXIT")
        {
            system("clear");
            exit(0);
        }
		else if (input.length() != 1 || index > 7)
			std::cout << "Invalid index. Please enter a digit from 1 to 8." << std::endl << std::endl;
		else if (this->_contact_array[index].get_first_name() == "")
		{
			std::cout << "No record at index [" << index + 1 << "]." << std::endl;
			std::cout << "SEARCH for another, or ADD a contact and try again." << std::endl << std::endl;
		}
		else
		{
			std::cout << "----------CONTACT ["<< index + 1 << "]----------" << std::endl;
			std::cout << "First Name    : " << this->_contact_array[index].get_first_name() << std::endl;
			std::cout << "Last Name     : " << this->_contact_array[index].get_last_name() << std::endl;
			std::cout << "Nickname      : " << this->_contact_array[index].get_nickname() << std::endl;
			std::cout << "Phone Number  : " << this->_contact_array[index].get_phone_number() << std::endl;
			std::cout << "Darkest Secret: " << this->_contact_array[index].get_secret() << std::endl << std::endl;
		}
		wait_for_enter();
	}
}

/**
 * @brief Display contact table
 */
void	PhoneBook::display_contact_table(void)
{
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contact_array[i].get_first_name() == "")
			break ;
		else
		{
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << i + 1;
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << truncate(this->_contact_array[i].get_first_name());
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << truncate(this->_contact_array[i].get_last_name());
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << truncate(this->_contact_array[i].get_nickname());
			std::cout << std::setw(1) << "|" << std::endl;
			std::cout << "+----------+----------+----------+----------+" << std::endl;
		}
	}
}

/**
 * @brief Sets contact details accordingly
 * @param t_contact Contact object
 * @return true if successfully and validly set, false otherwise
 */
bool PhoneBook::set_contact_details(Contact &t_contact)
{
	if (parse_and_set_input("Enter First Name: ", t_contact, &Contact::set_first_name) == false)
		return (false);
	if (parse_and_set_input("Enter Last Name: ", t_contact, &Contact::set_last_name) == false)
		return (false);
	if (parse_and_set_input("Enter Nickname: ", t_contact, &Contact::set_nickname) == false)
		return (false);
	if (parse_and_set_input("Enter Phone Number: ", t_contact, &Contact::set_phone_number) == false)
		return (false);
	if (parse_and_set_input("Enter Darkest Secret: ", t_contact, &Contact::set_secret) == false)
		return (false);
	system("clear");
	return (true);
}

/**
 * @brief Parses and sets input for adding a contact
 * @param prompt Prompt message
 * @param t_contact Contact object
 * @param contact_field Member function of Contact class
 * @return true if successfully and validly set, false otherwise
 */
bool PhoneBook::parse_and_set_input(std::string prompt, Contact &t_contact, void (Contact::*contact_field)(std::string))
{
	std::string input;

	while (1)
	{
		system("clear");
		std::cout << "Enter BACK to return to the Main Menu." << std::endl;
		std::cout << "Enter EXIT to exit the Phonebook." << std::endl << std::endl;
		get_input(prompt, input);
		if (input.empty())
			continue ;
		else if (input == "BACK")
		{
			system("clear");
			std::cout << "Contact not added" << std::endl << std::endl;
			wait_for_enter();
			return (false);
		}
		else if (input == "EXIT")
        {
            system("clear");
            exit(0);
        }
		else
		{
			(t_contact.*contact_field)(input);
			break;
		}
	}
	return (true);
}
