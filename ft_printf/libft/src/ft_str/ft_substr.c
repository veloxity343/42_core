/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:54:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 15:53:30 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (0);
	while (start-- && *s)
		s++;
	slen = ft_strlen(s);
	if (len > 2147483646)
		return (0);
	else if (len > slen)
		len = slen;
	str = (char *) malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *s = argv[1];
		int start = ft_atoi(argv[2]);
		size_t len = ft_atoi(argv[3]);
		char *result = ft_substr(s, start, len);
		if (result == NULL)
		{
			printf("Memory allocation failed\n");
			return (1);
		}
		printf("%s\n", result);
		free(result);
	}
	return (0);
}*/