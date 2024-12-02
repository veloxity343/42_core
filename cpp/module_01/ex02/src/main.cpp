/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:10:41 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/27 11:10:42 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string:\t" << &string << std::endl;
	std::cout << "Address of stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Address of stringREF:\t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string:\t\t" << string <<std::endl;
	std::cout << "Value pointed to by stringPTR:\t" << *stringPTR <<std::endl;
	std::cout << "Value of stringREF:\t\t" << stringREF <<std::endl;

	return (EXIT_SUCCESS);
}
