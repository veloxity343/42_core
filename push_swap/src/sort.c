/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:23:15 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/29 15:34:08 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack_a(t_node **stack, int point)
{
	int	ra_size;
	int	rra_size;

	ra_size = count_forward(*stack, point);
	rra_size = count_backward(*stack, point);
	if (ra_size == 0)
		return ;
	else if (ra_size > rra_size)
		while (rra_size--)
			rev_rotate(stack, "rra", -1);
	else
		while (ra_size--)
			rotate(stack, "ra", 1);
}

void	assign_index(int len, t_node **stack, int *sorted_lst)
{
	int		i;
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->data == sorted_lst[i])
			{
				temp->s_index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	sort_int_array(int **tab, int size)
{
	int	i;
	int	temp;
	int	*new;

	new = *tab;
	i = 0;
	while (i < (size - 1))
	{
		if (new[i] > new[i + 1])
		{
			temp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	*tab = new;
}

int	get_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	sort_index(t_node **stack)
{
	int		len;
	t_node	*temp;
	int		i;
	int		*sorted_lst;

	temp = *stack;
	len = get_len(*stack);
	sorted_lst = malloc(sizeof(int) * len);
	if (!sorted_lst)
		return ;
	i = 0;
	while (temp)
	{
		sorted_lst[i++] = temp->data;
		temp = temp->next;
	}
	sort_int_array(&sorted_lst, len);
	temp = *stack;
	assign_index(len, &temp, sorted_lst);
	*stack = temp;
	free(sorted_lst);
}
