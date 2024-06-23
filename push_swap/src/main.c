/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:43 by rcheong           #+#    #+#             */
/*   Updated: 2024/05/11 09:56:46 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_position(a, b);
		find_cost(a, b);
		cheapest_pos = find_cheapest(b);
		reorder_a_and_b(cheapest_pos, a, b);
		push(a, b, "pa");
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
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) > 3)
	{
		midpoint_sorting(a, &b);
		sort_three(a);
	}
	push_to_a(a, &b);
	sort_stack_a(a, 0);
	free_lst(&b);
	return ;
}

static char	*build_string(char *argv[], char **stack)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!argv[i][0])
		{
			free(*stack);
			error_exit(0);
			ft_printf("Empty string for argument %d.", argv[i]);
		}
		*stack = ft_strjoin(*stack, argv[i++]);
		*stack = ft_strjoin(*stack, ' ');
	}
	return (*stack);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	char	*stack;

	if (argc < 2)
		ft_printf("Error: Insufficient arguments. Usage: %s <numbers>\n",
			argv[0]);
	else
	{
		stack = NULL;
		stack = build_string(argv, &stack);
		if (!is_valid(&stack) || !check_duplicate(&stack))
		{
			error_exit(0);
			ft_printf("Arguments must be unique numbers.\n");
		}
		a = NULL;
		build_stack(&buffer, &a);
		sorting_index(&a);
		push_swap(&a);
		free_lst(&a);
	}
	return (0);
}
