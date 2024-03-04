/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:45:35 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 14:47:51 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_c;
	const char	*src_c;

	dst_c = dst;
	src_c = src;
	if (!len || dst == src)
		return (dst);
	if (dst > src && dst < src + len)
	{
		while (len--)
			dst_c[len] = src_c[len];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		char *dest = argv[1];
		char *src = argv[2];
		size_t size = ft_atoi(argv[3]);
		ft_memmove(dest, src, size);
		printf("%s\n", dest);
	}
	return (0);
}*/