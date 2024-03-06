/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:49:50 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 11:49:57 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
    if (!s)
        return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char *string = argv[1];
		int fd = ft_atoi(argv[2]);
		printf("%s\n", string);
		printf("%d\n", fd);
		ft_putendl_fd(string, fd);
	}
	return (0);
}*/