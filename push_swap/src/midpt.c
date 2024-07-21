/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:04:10 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 16:32:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Pushes top element from A to B, update counter
*/
void	push_to_b(t_node **a, t_node **b, int *i, int *nett_nodes)
{
	push(b, a, "pb");
	(*i)--;
	(*nett_nodes)--;
}

/*
@brief Calculates median value of stack based on indices
@return Rounded median value of stack
*/
int	get_midpt(t_node *stack)
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

/*
@brief Send from A to B based on median
@details 
1. If index of top element in A < median value, push to B
2. Otherwise if next element < median, rotate and push
3. Otherwise if bottom element < median, rev-rotate and push
4. Else just rotate till condition met
*/
void	send_to_b(t_node **a, t_node **b, int *nett_nodes)
{
	int	mid_pt;
	int	i;

	mid_pt = get_midpt(*a);
	i = (((*nett_nodes) / 2) + 1);
	while (i > 0)
	{
		if ((*a)->s_index < mid_pt)
			push_to_b(a, b, &i, nett_nodes);
		else if ((*a)->next->s_index < mid_pt)
		{
			rotate(a, "ra", 1);
			push_to_b(a, b, &i, nett_nodes);
		}
		else if ((lst_last(*a)->s_index < mid_pt))
		{
			rev_rotate(a, "rra", -1);
			push_to_b(a, b, &i, nett_nodes);
		}
		else
			rotate(a, "ra", 1);
	}
}

/*
@brief Send all but last 3 elements in A to B

*/
void	midpt_sorting(t_node **a, t_node **b)
{
	int	nett_nodes;

	nett_nodes = get_len(*a) - 3;
	while (nett_nodes > 0)
		send_to_b(a, b, &nett_nodes);
}
