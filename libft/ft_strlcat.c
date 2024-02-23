/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:48:21 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/23 15:48:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < size - 1)
		i++;
	j = 0;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size - 1)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *dest = argv[1];
		char *src = argv[2];
		size_t size = ft_atoi(argv[3]);
		size_t result = ft_strlcat(dest, src, size);
		printf("Modified string: %s\n", dest);
		printf("Length catenated: %zu\n", result);
	}
	return (0);
}*/