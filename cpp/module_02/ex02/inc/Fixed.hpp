/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:51:59 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 10:47:54 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <limits>

class Fixed
{
	private:
		int					_fp_value;
		static const int	_fract_bits;
	public:
		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		bool operator>(Fixed fixed)const;
		bool operator<(Fixed fixed)const;
		bool operator>=(Fixed fixed)const;
		bool operator<=(Fixed fixed)const;
		bool operator==(Fixed fixed)const;
		bool operator!=(Fixed fixed)const;
		float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		float toFloat(void)const;
		int toInt(void)const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);
