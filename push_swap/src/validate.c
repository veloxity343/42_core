/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:57:01 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 16:48:41 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Free array and string
@return Exit and produce error message
*/
static void	free_storage(char ***storage, char **str)
{
	free_array(storage);
	free(*str);
	error_exit(0);
}

/*
@brief Checks if the string has duplicates
@details Split and compare substrings delimited by space
@return 1 if no dup, 0 otherwise
*/
int	have_dup(char **str)
{
	char	**storage;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	storage = ft_split(*str, ' ');
	while (storage[i])
	{
		j = i + 1;
		while (storage[j])
		{
			len = ft_strlen(storage[i]);
			if (ft_strlen(storage[j]) > ft_strlen(storage[i]))
				len = ft_strlen(storage[j]);
			if (ft_strncmp(storage[i], storage[j], len) == 0)
				free_storage(&storage, str);
			j++;
		}
		i++;
	}
	free_array(&storage);
	return (1);
}

/*
@brief Checks if a string represents a valid number
@details "0", check long `ft_atol`
@return 1 if the string represents a valid number, 0 otherwise
*/
static int	is_num(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!ft_strncmp(str, "0", i))
		return (0);
	else
	{
		if (!ft_atol(str))
			return (1);
		return (0);
	}
}

/*
@brief Checks if a character is valid
= whitespace, digits, signum
@return 1 if the character is valid, 0 otherwise
*/
static int	is_valid(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ' || (c >= '0' && c <= '9')
		|| c == '-' || c == '+')
		return (1);
	else
		return (0);
}

/*
@brief Validates a string and its components
@return 1 if the string and its components are valid, 0 otherwise
*/
int	check_valid(char **str)
{
	int		i;
	char	**storage;

	i = 0;
	while ((*str)[i])
	{
		if (is_valid((*str)[i]))
			i++;
		else
		{
			free(*str);
			return (0);
		}
	}
	i = 0;
	storage = ft_split(*str, ' ');
	while (storage[i])
	{
		if (is_num(storage[i]))
			free_storage(&storage, str);
		i++;
	}
	free_array(&storage);
	return (1);
}
