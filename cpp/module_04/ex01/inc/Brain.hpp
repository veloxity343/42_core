/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:03:17 by rcheong           #+#    #+#             */
/*   Updated: 2025/01/18 11:03:18 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);

		virtual ~Brain();

		Brain &operator=(const Brain &src);

		const std::string getIdea(size_t i)const;
		const std::string *getIdeaAddress(size_t i)const;

		void setIdea(size_t i, std::string idea);
};
