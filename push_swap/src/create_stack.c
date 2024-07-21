/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:56:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/21 15:45:52 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
@brief Check if dup in list
@details Check if each element corresponds to the next
*/
static int	check_dup(t_node **a, long num)
{
	t_node	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->data == (int)num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

/*
@brief Free, exit and error if nbr is above limit or dup
*/
static void	free_stuff(long num, t_node **a, char ***str)
{
	if (num > INT_MAX || num < INT_MIN || check_dup(a, num))
	{
		free_lst(a);
		free_array(str);
		error_exit(0);
	}
}

/*
@brief Builds list from array of string rep nbrs
@param storage: Pointer to array of strings -> nodes
@param a: Pointers to top of list to be created
@details
1. Splits into substrings `ft_split` and free ori
3. Iterates substring, convert to long `ft_atol`
4. Checks for validity and dups
5. Create new node for each valid nbr and add to list
6. Frees array of strings
*/
void	build_stack(char **storage, t_node **a)
{
	t_node	*nod;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[i])
	{
		if (ft_strlen(str[i]) > 11 && (str[i][0] != '-'))
			free_stuff(num, a, &str);
		num = ft_atol(str[i]);
		free_stuff(num, a, &str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->s_index = 0;
		if (!*a)
			(*a) = nod;
		else
			lst_last(*a)->next = nod;
		i++;
	}
	free_array(&str);
}
