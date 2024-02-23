/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:51:31 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/23 16:01:08 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int i)
{
	int	j;

	j = ft_strlen(str);
	if (i == 0)
		return ((char *)str + j);
	while (j >= 0)
	{
		if (str[j] == i)
			return ((char *)str + j);
		j--;
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