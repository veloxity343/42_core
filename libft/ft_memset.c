#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	char *ptr;

	ptr = (char *)str;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (str);
}