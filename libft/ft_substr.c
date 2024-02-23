/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:54:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/23 17:16:44 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
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