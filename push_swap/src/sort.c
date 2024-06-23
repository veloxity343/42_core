#include "../includes/push_swap.h"

int	find_len(t_node *stack)
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

void	assign_index(int len, t_node **stack, int *sorted_list)
{
	int		i;
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->data == sorted_list[i])
			{
				temp->s_index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void    sort_array(int **tab, int size)
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

void    sorting_index(t_node **stack)
{
    int     len;
    t_node  *temp;
    int     i;
    int     *sorted_lst;

    temp = *stack;
    len = find_len(*stack);
    sorted_lst = malloc(sizeof(int) * len);
    if (!sorted_lst)
        return ;
    i = 0;
    while (temp)
    {
        sorted_lst[i++] = temp->data;
        temp = temp->next;
    }
    sort_array(&sorted_lst, len);
	temp = *stack;
	assign_index(len, &temp, sorted_lst);
	*stack = temp;
	free(sorted_lst);
}