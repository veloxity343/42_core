/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:26:56 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 14:44:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include "PhoneBookUtils.hpp"
# include <iomanip>

/**
 * @brief PhoneBook class
 * @details Contains contact array and methods to add and search contacts
 * @param _contact_array Array of contacts
 * @param _index Index of contact array
 */
class PhoneBook
{
	private:
		Contact	_contact_array[8];
		int		_index;

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void);
		void	display_contact_table(void);
		bool	set_contact_details(Contact &t_contact);
		bool	parse_and_set_input(std::string prompt, Contact &t_contact, void (Contact::*contact_field)(std::string));

};

#endif
