#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t needle_len;

	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	needle_len = 0;
	while (needle[needle_len] != '\0')
		++needle_len;
	while (*haystack != '\0' && n >= needle_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, needle_len) == 0)
		{
			return ((char *)haystack);
		}
		++haystack;
		--n;
	}
	return (NULL);
}