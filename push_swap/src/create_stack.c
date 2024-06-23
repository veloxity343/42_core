/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/05/11 11:41:06 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	have_duplicates(t_node **a, long num)
{
	t_node	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->data == (int)num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	free_stuff(long num, t_node **a, char ***str)
{
	if (num > INT_MAX || num < INT_MIN || have_duplicates(a, num))
	{
		free_lst(a);
		free_array(str);
		error_exit(0);
	}
}

void	build_stack(char **buffer, t_node **a)
{
	t_node	*node;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*buffer, ' ');
	free(*buffer);
	while (str[i])
	{
		if (ft_strlen(str[i]) > 11 && (str[i][0] != '-'))
			free_stuff(num, a, &str);
		num = ft_atoi(str[i]);
		free_stuff(num, a, &str);
		node = malloc(sizeof(t_node));
		node->data = num;
		node->next = NULL;
		node->s_index = 0;
		if (!*a)
			(*a) = node;
		else
			lst_last(*a)->next = node;
		i++;
	}
	free_array(&str);
}
