/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:53:30 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/23 16:26:36 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_mem;

	alloc_mem = malloc(size * count);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, count);
	return (alloc_mem);
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