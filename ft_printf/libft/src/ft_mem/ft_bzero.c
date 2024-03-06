/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:42:15 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:38:03 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char *str = argv[1];
		size_t n = ft_atoi(argv[2]);
		ft_bzero(str, n);
		printf("%s\n", str);
	}
	return (0);
}*/