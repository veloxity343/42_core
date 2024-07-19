/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:24:47 by stan              #+#    #+#             */
/*   Updated: 2024/06/19 21:38:49 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tokens_join(const char **tokens, size_t len, const char *sep)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = ft_calloc(sizeof(char), 1);
	if (len <= 0)
		return (ret);
	ft_str_append(&ret, tokens[i++]);
	while (i < len)
	{
		ft_str_append(&ret, sep);
		ft_str_append(&ret, tokens[i]);
		++i;
	}
	return (ret);
}
