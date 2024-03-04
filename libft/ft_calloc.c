/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:53:30 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 14:48:31 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	if (size > 2147483647 / count)
		return (0);
	ptr = (void *)malloc(size * count);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		size_t count = atoi(argv[1]);
		size_t size = atoi(argv[2]);
		void *ptr = ft_calloc(count, size);
		if (ptr == NULL)
		{
			printf("Memory allocation failed.\n");
			return (1);
		}
		printf("Memory allocated for %d elements of size %d bytes each.\n",
			count, size);
		free(ptr);
	}
	return (0);
}*/