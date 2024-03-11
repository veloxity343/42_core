/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:31:42 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/11 14:12:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
