/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:53:41 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/23 16:30:04 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = ft_strlen(str);
	ptr = (char *)malloc(sizeof(*ptr) * (j + 1));
	while (i < j)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char *result = ft_strdup(argv[1]);
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