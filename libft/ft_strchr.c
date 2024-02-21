#include "libft.h"

char	*ft_strchr(const char *str, int i)
{
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	if (i == '\0')
		return ((char *)str);
	return (0);
}