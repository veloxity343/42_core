#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

#include <stdio.h>

int	main(void)
{
	t_list	*list;
	t_list	*new_node;

	list = NULL;
	new_node = ft_lstnew("Node 1", sizeof("Node 1"));
	ft_lstadd_front(&list, new_node);
	new_node = ft_lstnew("Node 2", sizeof("Node 2"));

	ft_lstadd_front(&list, new_node);
    
    ft_lstclear(&list, free);
	return (0);
}

/*int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		t_list *new_node = ft_lstnew(argv[1]);
		if (!new_node)
		{
			printf("Memory allocation failed!\n");
			return (1);
		}
		t_list *lst = NULL;
		ft_lstadd_front(&lst, new_node);
		while (lst)
		{
			printf("%s\n", (char *)lst->content);
			lst = lst->next;
		}
		free(new_node);
	}
	return (0);
}*/