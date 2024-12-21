/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:52:02 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 10:44:39 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
}

Fixed::Fixed(const int input)
{
	this->_fp_value = input << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	if (fixed.toFloat() == 0.0f)
	{
		std::cerr << "Error: Division by zero detected." << std::endl;
		return std::numeric_limits<float>::infinity();
	}
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_fp_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_fp_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	
	++this->_fp_value;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->_fp_value;
	return (tmp);
}

float Fixed::toFloat() const {
    return static_cast<float>(this->_fp_value) / (1 << this->_fract_bits);
}

/* float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
} */

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

int	Fixed::getRawBits(void)const
{
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
