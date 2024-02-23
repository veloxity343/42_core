#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char *ptr;
	size_t i;

	i = 0;
	ptr = (char *)str;
	while (i < n)
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}