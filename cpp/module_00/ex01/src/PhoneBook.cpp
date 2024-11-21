/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:07 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 13:46:00 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

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
	std::cout << "Contact added Successfully" << std::endl;
	wait_for_enter();
}

void	PhoneBook::search_contact(void)
{
	std::string	input;
	size_t		index;

	system("clear");
	while (1)
	{
		display_contact_table();
		std::cout << "Enter BACK to return to main menu." << std::endl;
		get_input("Enter index to display contact [1 - 8]: ", input);
		index = input[0] - '0' - 1;
		system("clear");
		if (input == "BACK" || input == "back")
			return ;
		else if (input.length() != 1 || index > 7)
			std::cout << "Invalid index! Please enter a digit from 1 to 8." << std::endl;
		else if (this->_contact_array[index].get_first_name() == "")
			std::cout << "No record at index [" << index + 1 << "]. ADD a contact and try again." << std::endl;
		else
		{
			std::cout << "----------CONTACT ["<< index + 1 << "]----------" << std::endl;
			std::cout << "First Name    : " << this->_contact_array[index].get_first_name() << std::endl;
			std::cout << "Last Name     : " << this->_contact_array[index].get_last_name() << std::endl;
			std::cout << "Nickname      : " << this->_contact_array[index].get_nickname() << std::endl;
			std::cout << "Phone Number  : " << this->_contact_array[index].get_phone_number() << std::endl;
			std::cout << "Darkest Secret: " << this->_contact_array[index].get_secret() << std::endl << std::endl;
			wait_for_enter();
			return ;
		}
		wait_for_enter();
	}
}

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

bool PhoneBook::parse_and_set_input(std::string prompt, Contact &t_contact, void (Contact::*func)(std::string))
{
	std::string input;

	while (1)
	{
		system("clear");
		std::cout << "Enter BACK to return to main menu." << std::endl;
		get_input(prompt, input);
		if (input.empty())
			continue ;
		else if (input == "BACK" || input == "back")
		{
			system("clear");
			std::cout << "Contact not added" << std::endl;
			wait_for_enter();
			return (false);
		}
		else
		{
			(t_contact.*func)(input);
			break;
		}
	}
	return (true);
}
