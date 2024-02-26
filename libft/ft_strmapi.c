/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:44:28 by rcheong           #+#    #+#             */
/*   Updated: 2024/02/26 13:56:17 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f(i, s[i]);
	str[i] = 0;
	return (str);
}

/*#include <stdio.h>

char	to_upper(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char *input_string = argv[1];
		char *result = ft_strmapi(input_string, &to_upper);
		printf("%s\n", result);
		free(result);
	}
	return (0);
}*/