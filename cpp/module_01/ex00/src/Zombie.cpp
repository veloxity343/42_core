/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:17:16 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/07 16:34:03 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string s) : _name(s)
{
	std::cout << "Hello, " << _name << " wood laik to vizit ur houz for a midnite znack..." << std::endl << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " ate a Cherry Bomb and \033[1;31mdied\033[0m." << std::endl << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl << std::endl;
}
