/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:52:28 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:50:52 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	needle_len = 0;
	while (needle[needle_len] != '\0')
		++needle_len;
	while (*haystack != '\0' && len >= needle_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle,
				needle_len) == 0)
		{
			return ((char *)haystack);
		}
		++haystack;
		--len;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *haystack = argv[1];
		char *needle = argv[2];
		size_t n = ft_atoi(argv[3]);
		int result = ft_strnstr(haystack, needle, n);
		printf("%s\n", result);
	}
	return (0);
}*/