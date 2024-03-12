/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:31:28 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/11 14:11:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pad_width(int width, int size, int zero)
{
	int	count;

	count = 0;
	while (width - size > 0)
	{
		if (zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		width--;
	}
	return (count);
}

int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_putchar(c);
	count += ft_pad_width(flags.width, 1, flags.zero);
	if (c == '\0')
		return (ft_putchar('\0'));
	if (flags.left == 0)
		count += ft_putchar(c);
	return (count);
}
