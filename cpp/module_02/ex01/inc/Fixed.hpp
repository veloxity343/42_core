/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:51:40 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 09:51:41 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		float toFloat(void)const;
		int toInt(void)const;
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
