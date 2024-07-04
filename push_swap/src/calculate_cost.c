/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:10:04 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/29 15:57:59 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	assign_pos(t_node **a, t_node **b)
{
	int		i;
	t_node	*temp1;
	t_node	*temp2;

	i = 0;
	temp1 = *a;
	temp2 = *b;
	while (temp1)
	{
		temp1->pos = i++;
		temp1 = temp1->next;
	}
	i = 0;
	while (temp2)
	{
		temp2->pos = i++;
		temp2 = temp2->next;
	}
}

int	count_forward(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->s_index != point)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	count_backward(t_node *stack, int point)
{
	int	i;

	i = 0;
	while (stack->s_index != point)
		stack = stack->next;
	stack = stack->next;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i + 1);
}

void	get_cost(t_node **a, t_node **b)
{
	int		size_b;
	t_node	*temp_b;
	int		back_moves;
	int		target_index;

	temp_b = *b;
	size_b = get_len(*b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->cost_b > size_b / 2)
			temp_b->cost_b = (temp_b->pos - size_b);
		target_index = get_target_index(a, &temp_b);
		back_moves = count_backward(*a, target_index);
		temp_b->cost_a = count_forward(*a, target_index);
		if (back_moves < temp_b->cost_a)
			temp_b->cost_a = back_moves * -1;
		temp_b = temp_b->next;
	}
}

int	get_cheapest(t_node **b)
{
	int		cheapest;
	t_node	*temp;
	int		cost_a;
	int		cost_b;
	int		cheapest_pos;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		cost_a = temp->cost_a;
		if (cost_a < 0)
			cost_a = temp->cost_a * -1;
		cost_b = temp->cost_b;
		if (cost_b < 0)
			cost_b = temp->cost_b * -1;
		if (cheapest > (cost_a + cost_b))
		{
			cheapest = (cost_a + cost_b);
			cheapest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (cheapest_pos);
}
