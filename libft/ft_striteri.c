/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:55:13 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 14:04:55 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (*s)
		f(i++, s++);
}

/*#include <stdio.h>

void	print_index_char(unsigned int index, char *c)
{
	printf("%c\n", *c);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char *input_string = argv[1];
		ft_striteri(input_string, &print_index_char);
	}
	return (0);
}*/