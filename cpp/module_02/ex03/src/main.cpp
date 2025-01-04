/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:48:50 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/23 14:55:29 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cstdlib>

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(int argc, char *argv[])
{
	if (argc != 9)
	{
		std::cerr << "Usage: " << argv[0] << "<x1> <y1> <x2> <y2> <x3> <y3> <pointX> <pointY>" << std::endl;
		return (1);
	}
	// Note the use of atof (ascii to float) is to supplement stof which is not available in c++98
	float x1 = std::atof(argv[1]);
	float y1 = std::atof(argv[2]);
	float x2 = std::atof(argv[3]);
	float y2 = std::atof(argv[4]);
	float x3 = std::atof(argv[5]);
	float y3 = std::atof(argv[6]);
	float test_x = std::atof(argv[7]);
	float test_y = std::atof(argv[8]);
	
	Point a(x1, y1);
	Point b(x2, y2);
	Point c(x3, y3);
	Point point(test_x, test_y);
	
	std::cout << "\033[0;33mTriangle vertices:\033[0m" << std::endl;
	std::cout << "\ta" << a << std::endl;
	std::cout << "\tb" << b << std::endl;
	std::cout << "\tc" << c << std::endl;
	
	std::cout << "\033[0;34mTest point:\033[0m" << std::endl;
	std::cout << "\tp" << point << std::endl;
	
	std::cout << "Result: ";
	if (bsp(a, b, c, point))
		std::cout << "\033[32mTRUE\033[0m (The point is inside the triangle)" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m (The point is outside the triangle)" << std::endl;
	
	return (0);
}
