/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:34:57 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:39:43 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'))
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int	input = argv[1][0];
		int	result = ft_isalnum(input);
		printf("%d\n", result);
	}
	return (0);
}*/