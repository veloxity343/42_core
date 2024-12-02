/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:17:05 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/30 12:17:06 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string s);
		~Zombie();
		void	announce(void)const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
