/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:26:48 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 17:13:05 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

/**
 * @brief Contact class
 * @details Contains contact details & setters/getters
 * @param _first_name First name of contact
 * @param _last_name Last name of contact
 * @param _nickname Nickname of contact
 * @param _phone_number Phone number of contact
 * @param _secret Darkest secret of contact
 */
class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_secret;

	public:
		void		set_first_name(std::string	first_name);
		void		set_last_name(std::string last_name);
		void		set_nickname(std::string nickname);
		void		set_phone_number(std::string phone_number);
		void		set_secret(std::string secret);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_secret(void);
};

#endif
