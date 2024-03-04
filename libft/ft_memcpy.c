/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:44:05 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 14:47:08 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*dstcpy;
	char		*dst_c;
	const char	*src_c;

	if (n && !dst && !src)
		return (0);
	dstcpy = dst;
	dst_c = dst;
	src_c = src;
	while (n--)
		*dst_c++ = *src_c++;
	return (dstcpy);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *dest = argv[1];
		char *src = argv[2];
		size_t n = ft_atoi(argv[3]);
		char *result = ft_memcpy(dest, src, n);
		printf("%s\n", result);
	}
	return (0);
}*/