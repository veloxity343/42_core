/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:51:53 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 14:24:19 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (n--)
		{
			if (*s1 != *s2++)
				return (*(unsigned char *)s1 - *(unsigned char *)--s2);
			if (!(*s1++))
				break ;
		}
	}
	return (0);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *s1 = argv[1];
		char *s2 = argv[2];
		size_t n = ft_atoi(argv[3]);
		int result = ft_strncmp(s1, s2, n);
		printf("%d\n", result);
	}
	return (0);
}*/