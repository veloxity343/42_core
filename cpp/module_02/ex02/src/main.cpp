/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:52:04 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 10:45:45 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));

	std::cout << a << "\t\tis a at start" << std::endl;
	std::cout << ++a << "\tis a at ++a" << std::endl;
	std::cout << a << "\tis a after ++a" << std::endl;
	std::cout << a++ <<"\tis a at a++" << std::endl;
	std::cout << a << "\tis a after a++" << std::endl;

	std::cout << b << "\t\tvalue of b" << std::endl;

	std::cout << Fixed::max(a, b) << "\t\tthe max of a and b" << std::endl;
	// std::cout << Fixed::min(a, b) << "\tthe min of a and b" << std::endl;

	return 0;
}

/* int	main(void)
{
	std::cout << "\n--- Comparison Operator Tests ---\n";
	Fixed a( 10 );
	Fixed b( 20 );
	Fixed c( -10 );
	Fixed d( 10 );

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	
	std::cout << "a == d: " << ( a == d ) << std::endl;
	std::cout << "a != b: " << ( a != b ) << std::endl;
	std::cout << "a < b: " << ( a < b ) << std::endl;
	std::cout << "c > b: " << ( c > b ) << std::endl;
	std::cout << "a <= d: " << ( a <= d ) << std::endl;
	std::cout << "b >= c: " << ( b >= c ) << std::endl;
	
	std::cout << "\n--- Arithmetic Operator Tests ---\n";
	Fixed x( 5.5f );
	Fixed y( 2 );

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	
	std::cout << "x + y: " << x + y << std::endl;
	std::cout << "x - y: " << x - y << std::endl;
	std::cout << "x * y: " << x * y << std::endl;
	std::cout << "x / y: " << x / y << std::endl;
	
	std::cout << "\n--- Edge Case Tests ---\n";
	a = Fixed( 10 );
	b = Fixed( 0 );
	
	std::cout << "a / b: " << a / b << std::endl;
	
	Fixed negA( -10 );
	Fixed negB( -2.5f );
	
	std::cout << "negA + negB: " << (negA + negB) << std::endl;
	std::cout << "negA - negB: " << (negA - negB) << std::endl;
	std::cout << "negA * negB: " << (negA * negB) << std::endl;
	std::cout << "negA / negB: " << (negA / negB) << std::endl;
	
	return 0;
} */
