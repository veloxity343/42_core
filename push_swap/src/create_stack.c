/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/23 16:02:46 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_dup(t_node **a, long num)
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
	if (num > INT_MAX || num < INT_MIN || check_dup(a, num))
	{
		free_lst(a);
		free_array(str);
		error_exit(0);
	}
}

void	build_stack(char **storage, t_node **a)
{
	t_node	*nod;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[i])
	{
		if (ft_strlen(str[i]) > 11 && (str[i][0] != '-'))
			free_stuff(num, a, &str);
		num = ft_atoi(str[i]);
		free_stuff(num, a, &str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->s_index = 0;
		if (!*a)
			(*a) = nod;
		else
			lst_last(*a)->next = nod;
		i++;
	}
	free_array(&str);
}
