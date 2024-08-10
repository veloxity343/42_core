/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:20:20 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/02/25 18:20:22 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	long	nb;
	int		i;
	int		neg;

	nb = n;
	i = 11;
	str[12] = '\0';
	neg = 0;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		neg = -1;
		nb *= -1;
	}
	while (nb != 0)
	{
		str[i--] = (char)(nb % 10) + '0';
		nb /= 10;
	}
	if (neg < 0)
		str[i--] = '-';
	ft_putstr_fd((char *)(str + (++i)), fd);
}
