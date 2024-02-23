/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:45 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/23 17:45:45 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	char *str;

	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
    return (str);
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