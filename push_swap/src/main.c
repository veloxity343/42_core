/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:43 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 16:43:49 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Push all elements b -> a efficiently
@param a, b: Pointers to the stacks a and b.
@details Optimal move - pos and cost -> push
*/
void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_pos(a, b);
		get_cost(a, b);
		cheapest_pos = get_cheapest(b);
		reorder_both(cheapest_pos, a, b);
		push(a, b, "pa");
	}
}

/*
@brief Sorts 3 elements
@details Chosen because 3! << 4!, 5!...
compares stack element indices and performs necessary operations
*/
void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->s_index;
	second = (*stack)->next->s_index;
	third = (*stack)->next->next->s_index;
	if ((first < second) && (second < third))
		return ;
	else if ((first < second) && (first < third))
	{
		swap(*stack, "sa");
		rotate(stack, "ra", 1);
	}
	else if ((first > second) && (first < third) && (second < third))
		swap(*stack, "sa");
	else if ((first < second) && (first > third))
		rev_rotate(stack, "rra", -1);
	else if ((first > second) && (first > third) && (second < third))
		rotate(stack, "ra", 1);
	else if ((first > second) && (first > third) && (second > third))
	{
		swap(*stack, "sa");
		rev_rotate(stack, "rra", -1);
	}
}

/*
@brief Starts performing algo to sort
@details
1. Checks if stack `is_sorted`. If it is, frees the stack and exits
2. If stack has two elements, swap operation
3. If stack has three elements, calls `sort_three`
4. If stack has more than three elements, calls `midpt_sorting` then `sort_three`
5. Pushes all elements B -> A then `sort_stack_a`
6. Frees B
*/
void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_lst(a);
		exit(0);
	}
	else if (get_len(*a) == 2)
		swap(*a, "sa");
	else if (get_len(*a) == 3)
		sort_three(a);
	else if (get_len(*a) > 3)
	{
		midpt_sorting(a, &b);
		sort_three(a);
	}
	push_to_a(a, &b);
	sort_stack_a(a, 0);
	free_lst(&b);
	return ;
}

/*
@brief Builds string from args
@param stack: Pointer to string - concatenated result
@details Cat args into a string with spaces.
Checks for empty args, exits with an error if found.
@return Concatenated string.
*/
static char	*build_string(char **argv, char **stack)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
		{
			free(*stack);
			error_exit(0);
		}
		*stack = ft_strjoin(*stack, argv[i++]);
		*stack = ft_strjoin(*stack, " ");
	}
	return (*stack);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	char	*stack;

	if (argc >= 2)
	{
		stack = NULL;
		stack = build_string(argv, &stack);
		if (!check_valid(&stack) || !have_dup(&stack))
			error_exit(0);
		a = NULL;
		build_stack(&stack, &a);
		sort_index(&a);
		push_swap(&a);
		free_lst(&a);
	}
	return (0);
}
