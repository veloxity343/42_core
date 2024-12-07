/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:10:41 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/06 15:36:14 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @param stringPTR stores the memory address of the variable "string".
 * @param stringREF works as an alias to the variable "string".
 * @details Although the addresses and values are the same in this case (all referring 
         to the same variable), the key takeaway is understanding the differences:
         - Pointers explicitly store and manage memory addresses and allow reassignment.
         - References act as aliases to existing variables and are fixed once initialized.
         Practical use cases:
         - Pointers are essential for dynamic memory allocation, nullable variables, 
           and reassignment.
         - References simplify passing arguments and accessing variables directly 
           without explicit dereferencing.
 */
int main(void)
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
