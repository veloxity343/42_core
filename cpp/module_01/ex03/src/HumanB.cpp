/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:29:45 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/27 13:33:07 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_is_armed = false;
	std::cout << this->_name <<" spawned." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " died." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_is_armed = true;
	std::cout << this->_name << " grabbed " << this->_weapon->getType() << " to fight with." << std::endl;
}

void HumanB::attack(void)
{
    if (this->_is_armed)
        std::cout << this->_name << " attacks with " << this->_weapon->getType() << "." << std::endl;
    else
        std::cout << this->_name << " attacks with fists." << std::endl;
}
