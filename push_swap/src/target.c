/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:42:26 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 16:33:29 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Sorts A based on target index
@param stack: Pointer to A
@param point: Target index to be sorted to
@details Sorts A by rotating or rev-rotating stack 
until target index is at the top
*/
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

/*
@brief Finds min and max indices in A
@param a_min: Pointer to min index.
@param a_max: Pointer to max index.
*/
void	get_min_max(int *a_min, int *a_max, t_node *temp)
{
	*a_min = temp->s_index;
	*a_max = temp->s_index;
	while (temp->next != NULL)
	{
		if (*a_min > temp->next->s_index)
			*a_min = temp->next->s_index;
		if (*a_max < temp->next->s_index)
			*a_max = temp->next->s_index;
		temp = temp->next;
	}
}

/*
@brief Determines min and max diff between indices of A and top element of B
@param min_pos_diff: Pointer to min +ve diff
@param max_diff: Pointer to max diff
*/
void	check_diff(int *min_pos_diff, int *max_diff,
									t_node **a, t_node **b)
{
	t_node	*temp_a;
	int		next_diff;

	temp_a = *a;
	*max_diff = temp_a->s_index - (*b)->s_index;
	*min_pos_diff = 2147483647;
	if ((temp_a->s_index - (*b)->s_index) > 0)
		*min_pos_diff = (temp_a->s_index - (*b)->s_index);
	while (temp_a->next)
	{
		next_diff = temp_a->next->s_index - (*b)->s_index;
		if (*max_diff < next_diff)
			*max_diff = next_diff;
		if (next_diff > 0 && *min_pos_diff > next_diff)
			*min_pos_diff = next_diff;
		temp_a = temp_a->next;
	}
}

/*
@brief Determines target index in A where element from b should be placed
@return int: Target index in A
*/
int	get_target_index(t_node **a, t_node **b)
{
	int		min_pos_diff;
	int		max_diff;
	int		target;
	int		a_min;
	int		a_max;

	target = 0;
	check_diff(&min_pos_diff, &max_diff, a, b);
	get_min_max(&a_min, &a_max, *a);
	if (max_diff > 0)
		target = min_pos_diff + (*b)->s_index;
	else if (max_diff < 0)
		target = a_min;
	return (target);
}
