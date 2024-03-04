/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:45 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 14:24:39 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		++s1;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, *(s1 + len - 1)))
		--len;
	return (ft_substr(s1, 0, len));
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