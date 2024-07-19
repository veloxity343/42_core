/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:53:57 by shatan            #+#    #+#             */
/*   Updated: 2024/06/19 12:39:22 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(t_stringstream *ss)
{
	int	len;

	len = 0;
	while (ss_read_argv(ss, NULL))
		len++;
	return (len);
}

char	**ft_str_to_argv(const char *str, int *argc)
{
	char			**ret;
	int				idx;
	t_stringstream	*ss;

	ss = ss_create(str);
	*argc = get_len(ss);
	ret = (char **)ft_calloc(sizeof(char *), *argc + 1);
	ss_reset(ss);
	idx = 0;
	while (ss_read_argv(ss, ret + idx))
		idx++;
	ss_destroy(ss);
	return (ret);
}
