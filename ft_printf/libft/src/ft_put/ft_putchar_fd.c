/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:49:18 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 11:49:27 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char input_char = argv[1][0];
		int fd = ft_atoi(argv[2]);
		printf("%c\n", input_char);
		printf("%d\n", fd);
		ft_putstr_fd(string, fd);
	}
	return (0);
}*/