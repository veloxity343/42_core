#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = ft_strlen(str);
	ptr = (char *)malloc(sizeof(*ptr) * (j + 1));
	while (i < j)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}