/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:14:08 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/02/25 18:14:11 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	a;
	unsigned int	begin;
	unsigned int	end;
	char			*str;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (s1[begin] != '\0' && check_trim(s1[begin], set))
		begin++;
	end = ft_strlen(s1);
	while (end > begin && (s1[end] == '\0' || check_trim(s1[end], set)))
		end--;
	if (!(s1[0] == '\0'))
		end++;
	str = malloc(sizeof(char) * ((end - begin) + 1));
	if (!str)
		return (NULL);
	a = 0;
	while (begin < end)
		str[a++] = s1[begin++];
	str[a] = '\0';
	return (str);
}
