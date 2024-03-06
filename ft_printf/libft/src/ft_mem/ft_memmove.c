/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:45:35 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 15:51:03 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	if (!len || dst == src)
		return (dst);
	if (dst > src && dst < src + len)
	{
		while (len--)
			dst_ptr[len] = src_ptr[len];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
