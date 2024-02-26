/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:41:54 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:46:19 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)b;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (b);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *str = argv[1];
		char c = argv[2][0];
		size_t len = ft_atoi(argv[3]);
		ft_memset(str, c, len);
		printf("%s\n", str);
	}
	return (0);
}*/