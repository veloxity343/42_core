/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:52:40 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 16:28:00 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Reorders a and b to move node with cheapest cost to target pos
@param cheapest_pos: Pos of node with cheapest cost
@details reorders both stacks to move node with cheapest cost to target pos
Performs simultaneous rotations or rev-rotations
*/
void	reorder_both(int cheapest_pos, t_node **a, t_node **b)
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

/*
@brief Simultaneously rev-rotate both stacks until specified moves reached
@param cost_a: Number needed for A
@param cost_b: Number needed for B
*/
void	rev_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		rev_rotate(a, " ", -1);
		rev_rotate(b, " ", -1);
		write(1, "rrr\n", 4);
		cost_a++;
		cost_b++;
	}
	rev_rotate(a, "rra", cost_a);
	rev_rotate(b, "rrb", cost_b);
}

/*
@brief Simultaneously rotate both stacks until specified moves reached
@param cost_a: Number needed for A
@param cost_b: Number needed for B
*/
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		rotate(a, " ", 1);
		rotate(b, " ", 1);
		write(1, "rr\n", 3);
		cost_a--;
		cost_b--;
	}
	rotate(a, "ra", cost_a);
	rotate(b, "rb", cost_b);
}
