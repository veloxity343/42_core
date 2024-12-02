/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:29:43 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/27 14:31:53 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name <<" spawned and grabbed " << this->_weapon.getType() << " to fight with." << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name << " died." << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with " << this->_weapon.getType() << "." << std::endl;
}
