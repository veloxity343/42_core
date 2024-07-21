/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:58 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 14:57:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Frees list and nodes in list individually
@param temp: Traverse list
@param temp2: Current node
*/
void	free_lst(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = (*stack);
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		temp2->next = NULL;
		free(temp2);
	}
}

/*
@brief Frees array of string and array itself
*/
void	free_array(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		i++;
	while (i >= 0)
		free((*str)[i--]);
	free(*str);
}

/*
@brief Finds last node in list
@param lst: Pointer to top of list.
@return pointer to the last node, NULL if empty
*/
t_node	*lst_last(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
@brief Check list sorted ascending
@param stack: Pointer to top of list
@details Iterates through list,
compare each node data with next node.
@return 1 if sorted, 0 otherwise
*/
int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
@brief Produce error message and exit
*/
void	error_exit(int nb)
{
	(void)nb;
	write(2, "Error\n", 6);
	exit(1);
}
