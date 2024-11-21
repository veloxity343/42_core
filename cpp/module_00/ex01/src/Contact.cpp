/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:04 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 17:12:35 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/**
 * @brief Sets first name of contact
 */
void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
}

/**
 * @brief Sets last name of contact
 */
void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
}

/**
 * @brief Sets nickname of contact
 */
void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

/**
 * @brief Sets phone number of contact
 */
void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
}

/**
 * @brief Sets darkest secret of contact
 */
void	Contact::set_secret(std::string secret)
{
	this->_secret = secret;
}

/**
 * @brief Gets first name of contact
 */
std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

/**
 * @brief Gets last name of contact
 */
std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

/**
 * @brief Gets nickname of contact
 */
std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

/**
 * @brief Gets phone number of contact
 */
std::string	Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

/**
 * @brief Gets darkest secret of contact
 */
std::string	Contact::get_secret(void)
{
	return (this->_secret);
}
