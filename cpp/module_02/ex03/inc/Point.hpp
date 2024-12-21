/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:48:44 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 10:54:26 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		~Point();
		Point &operator=(const Point &src);
		const Fixed &getX(void)const;
		const Fixed &getY(void)const;
};

std::ostream	&operator<<(std::ostream &o, Point const point);
