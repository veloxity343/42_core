/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:17:08 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/06 16:24:06 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Returning the heap-allcoated Zombie object allows
 * the object to be used beyond the lifetime of the function that created it
 */
Zombie *newZombie(std::string name)
{
	Zombie *elite = new Zombie(name);
	elite->announce();
	return (elite);
}
