#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}

#include <stdio.h>

void	double_value(void *content)
{
	int	*value;

	value = (int *)content;
	*value *= 2;
}

int	main(void)
{
	t_list *list = NULL;

	int i = 1;
	while (i <= 5)
	{
		int *data = (int *)malloc(sizeof(int));
		*data = i;

		t_list *new_node = ft_lstnew(data, sizeof(int));

		ft_lstadd_back(&list, new_node);
		i++;
	}

	void (*function_ptr)(void *) = &double_value;

	t_list *current = list;
	while (current)
	{
		function_ptr(current->content);
		current = current->next;
	}

	current = list;
	while (current)
	{
		int *data_ptr = (int *)current->content;
		printf("%d\n", *data_ptr);
		current = current->next;
	}

	ft_lstclear(&list, free);
	return (0);
}