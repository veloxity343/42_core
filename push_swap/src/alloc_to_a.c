/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:49:20 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/29 15:58:06 by rcheong          ###   ########.fr       */
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

void	reorder_a_b(int cheapest_pos, t_node **a, t_node **b)
{
	t_node	*temp;

	temp = *b;
	while (temp->pos != cheapest_pos)
		temp = temp->next;
	if ((temp->cost_a < 0) && (temp->cost_b < 0))
		rev_rotate_both(a, b, temp->cost_a, temp->cost_b);
	else if ((temp->cost_a > 0) && (temp->cost_b > 0))
		rotate_both(a, b, temp->cost_a, temp->cost_b);
	else if (temp->cost_b >= 0 && temp->cost_a <= 0)
	{
		rotate(b, "rb", temp->cost_b);
		rev_rotate(a, "rra", temp->cost_a);
	}
	else if (temp->cost_b <= 0 && temp->cost_a >= 0)
	{
		rev_rotate(b, "rrb", temp->cost_b);
		rotate(a, "ra", temp->cost_a);
	}
}

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
