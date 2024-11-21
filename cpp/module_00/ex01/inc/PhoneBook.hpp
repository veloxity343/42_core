/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:26:56 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 11:26:57 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include "PhoneBookUtils.hpp"
# include <iomanip>

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
		bool	parse_and_set_input(std::string prompt, Contact &t_contact, void (Contact::*func)(std::string));

};

#endif