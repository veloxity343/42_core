/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:48:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 12:55:56 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY())
{
	*this = copy;
}

Point::~Point()
{
}

Point &Point::operator=(const Point &src)
{
	if (this == &src)
		return *this;
	return *this;
}

const Fixed	&Point::getX(void)const
{
	return (this->_x);
}

const Fixed	&Point::getY(void)const
{
	return (this->_y);
}

std::ostream	&operator<<(std::ostream &o, Point const point)
{
	o << "(x = " << point.getX() << ", y = " << point.getY() << ")";
	return (o);
}
