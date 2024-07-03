/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:04:10 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/29 15:33:53 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_to_b(t_node **a, t_node **b, int *i, int *total_nodes_to_go)
{
	push(b, a, "pb");
	(*i)--;
	(*total_nodes_to_go)--;
}

int	find_midpt(t_node *stack)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (stack)
	{
		sum += stack->s_index;
		i++;
		stack = stack->next;
	}
	if (sum % i == 0)
		return (sum / i);
	else
		return ((sum / i) + 1);
}

void	send_to_b(t_node **a, t_node **b, int *total_nodes_to_go)
{
	int	mid_pt;
	int	i;

	mid_pt = find_midpt(*a);
	i = (((*total_nodes_to_go) / 2) + 1);
	while (i > 0)
	{
		if ((*a)->s_index < mid_pt)
			push_to_b(a, b, &i, total_nodes_to_go);
		else if ((*a)->next->s_index < mid_pt)
		{
			rotate(a, "ra", 1);
			push_to_b(a, b, &i, total_nodes_to_go);
		}
		else if ((lst_last(*a)->s_index < mid_pt))
		{
			rev_rotate(a, "rra", -1);
			push_to_b(a, b, &i, total_nodes_to_go);
		}
		else
			rotate(a, "ra", 1);
	}
}

void	midpt_sort(t_node **a, t_node **b)
{
	int	total_nodes_to_go;

	total_nodes_to_go = get_len(*a) - 3;
	while (total_nodes_to_go > 0)
		send_to_b(a, b, &total_nodes_to_go);
}
