/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:51:31 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:51:25 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char *str = argv[1];
		int i = argv[2][0];
		char *result = ft_strrchr(str, i);
		printf("%s\n", result);
	}
	return (0);
}*/