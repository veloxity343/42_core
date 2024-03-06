/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:41:09 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:37:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	input = argv[1][0];
		int	result = ft_isascii(input);
		printf("%d\n", result);
	}
	return (0);
}*/