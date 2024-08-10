/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:56:35 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/02/25 17:56:38 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	if (!s1 || !s2)
		return (NULL);
	a = 0;
	b = 0;
	c = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[b] != '\0')
		str[a++] = s1[b++];
	while (s2[c] != '\0')
		str[a++] = s2[c++];
	str[a] = '\0';
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char *str1 = "haha";
	char *str2 = "xxx";
	char *res = ft_strjoin(str1, str2);
	printf("%s", res);
	return 0;
}
*/