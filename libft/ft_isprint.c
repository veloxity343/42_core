/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:41:22 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:40:38 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	input = argv[1][0];
		int	result = ft_isprint(input);
		printf("%d\n", result);
	}
	return (0);
}*/