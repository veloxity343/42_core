/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:48:46 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 12:48:25 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Calculate the absolute area of a triangle formed by 3 points
 * @details Area = ​abs(x1​(y2 ​− y3​) + x2​(y3 ​− y1​) + x3​(y1 ​− y2​)) / 2
 */
static float area (const Point p1, const Point p2, const Point p3)
{
	float	area;

	area =	(
			( p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) )
			+ ( p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) )
			+ ( p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() ) )
			)
			/ 2;

	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

/**
 * @brief Determines if a point is inside a triangle
 * @details Uses Barycentric coordinate system i.e the sum of the areas of
 * the 3 triangles formed by the test point and the 3 vertices of the triangle.
 * If the sum of the 3 areas is equal to the area of the triangle, the point is inside.
 * Note: The point is considered outside if it is on the edge of the triangle.
 */
bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float d0, d1, d2, d3;
	bool ret_val = false;

	d0 = area(a, b, c);
	d1 = area(point, a, b);
	d2 = area(point, b, c);
	d3 = area(point, a, c);

	if ( d1 == 0 || d2 == 0 || d3 == 0)
		ret_val = false;
	else if ( d1 + d2 + d3 == d0 )
		ret_val = true;
	return (ret_val);
}
