/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:04:38 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 14:25:24 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_i_strlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		++len;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*s;
	unsigned int	nbr;

	len = ft_i_strlen(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (0);
	s[len] = 0;
	if (!n)
		s[0] = '0';
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	while (nbr)
	{
		s[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		s[--len] = '-';
	return (s);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int n = ft_atoi(argv[1]);
		char *result = ft_itoa(n);
		printf("%s\n", result);
	}
	return (0);
}*/