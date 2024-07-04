/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:44:29 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/29 16:40:07 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct t_list
{
	int				data;
	int				s_index;
	int				cost_a;
	int				cost_b;
	int				pos;
	struct t_list	*next;
}					t_node;

// main
void				push_swap(t_node **a);
void				push_to_a(t_node **a, t_node **b);

// validate
int					check_valid(char **str);
int					have_dup(char **str);

// utilities
void				error_exit(int nb);
int					is_sorted(t_node *stack);
t_node				*lst_last(t_node *lst);
void				free_array(char ***str);
void				free_lst(t_node **stack);

// creating stack
void				build_stack(char **storage, t_node **a);

// sorting index
void				sort_index(t_node **stack);
int					get_len(t_node *stack);
void				sort_int_array(int **tab, int size);
void				assign_index(int len, t_node **stack, int *sorted_lst);
void				sort_stack_a(t_node **stack, int point);

// operations
void				swap(t_node *stack, char *str);
void				push(t_node **stack_1, t_node **stack_2, char *str);
void				rotate(t_node **stack, char *str, int cost);
void				rev_rotate(t_node **stack, char *str, int cost);
void				sort_three(t_node **stack);
void				rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void				rev_rotate_both(t_node **a, t_node **b, int cost_a,
						int cost_b);
void				reorder_both(int cheapest_pos, t_node **a, t_node **b);

// midpoint operation
void				midpt_sorting(t_node **a, t_node **b);
void				send_to_b(t_node **a, t_node **b, int *nett_nodes);
int					get_midpt(t_node *stack);
void				push_to_b(t_node **a, t_node **b, int *i,
						int *nett_nodes);

// calculate cost
void				assign_pos(t_node **a, t_node **b);
void				get_cost(t_node **a, t_node **b);
int					get_cheapest(t_node **b);
int					count_forward(t_node *stack, int point);
int					count_backward(t_node *stack, int point);

// get target
int					get_target_index(t_node **a, t_node **b);
void				get_min_max(int *a_min, int *a_max, t_node *temp);
void				check_diff(int *min_pos_diff, int *max_diff, t_node **a,
						t_node **b);

// checker
void				checker(t_node **a, t_node **b);

#endif
