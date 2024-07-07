/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:43 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/29 16:38:00 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

	if (argc < 2)
	{
		ft_printf("Usage: %s <numbers>", argv[0]);
		return (1);
	}
	else
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
