/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:23:15 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 14:57:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Assigns indices to nodes by sorted pos
@param len: Number of elements in sorted list
@param sorted_lst: Array of sorted values
@details Index stored in `s_index` field of each node.
*/
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

/*
@brief Bubble sort int array
@param tab: Pointers to array of ints
@param size: Number of elements in array
@details Performs in-place bubble sort int array
Iterates through array, swap adjacent elements if unsorted
*/
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

/*
@brief Computes length of list
@return Number of nodes
*/
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

/*
@brief Sorts nodes by data, assigns sorted indices
@details
1. Computes length of list
2. Malloc for storing node data
3. Sorts array of node data `sort_int_array`
4. Assigns indices to nodes by position 
in sorted array `assign_index`
5. Frees sorted data array
*/
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
