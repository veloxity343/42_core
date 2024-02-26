/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:45 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 12:16:25 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start + 1;
	trimmed = (char *)malloc(len);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len);
	return (trimmed);
}

/*#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        char *str = argv[1];
        char *trim = argv[2];
        char *result = ft_strtrim(str, trim);
        if (result == NULL)
        {
            printf("Trim failed\n");
            return (1);
        }
        printf("%s\n", result);
        free (result);
    }
    return (0);
}*/