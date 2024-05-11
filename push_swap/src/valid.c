/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:57:01 by rcheong           #+#    #+#             */
/*   Updated: 2024/05/11 11:37:39 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_buffer(char ***buffer, char **str)
{
	free_array(buffer);
	free(*str);
	error_exit(0);
}

int	check_duplicate(char **str)
{
	char	**buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = ft_split(*str, ' ');
	while (buffer[i])
	{
		j = i + 1;
		while (buffer[j])
		{
			if (strcmp(buffer[i], buffer[j]) == 0)
				free_buffer(&buffer, str);
			j++;
		}
		i++;
	}
	free_array(&buffer);
	return (1);
}

static int	check_numeric(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!ft_strncmp(str, "0", i))
		return (0);
	else
	{
		if (!ft_atoi(str))
			return (1);
		return (0);
	}
}

static int	check_valid(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || (c >= '0' && c <= '9') || c == '-'
		|| c == '+')
		return (1);
	else
		return (0);
}

int	is_valid(char **str)
{
	int		i;
	char	**buffer;

	i = 0;
	while (*str[i])
	{
		if (check_valid(*str[i]))
			i++;
		else
		{
			free(*str);
			return (0);
		}
	}
	i = 0;
	buffer = ft_split(*str, ' ');
	while (buffer[i])
	{
		if (check_numeric(buffer[i]))
			free_buffer(&buffer, str);
		i++;
	}
	free_array(&buffer);
	return (1);
}
