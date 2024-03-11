/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:00:51 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/11 14:11:25 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_ptrhex_len(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 16;
	}
	return (len);
}
