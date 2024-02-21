#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *alloc_mem;

	alloc_mem = malloc(size * count);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, count);
	return (alloc_mem);
}