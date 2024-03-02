#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	t_list *list;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	int size;

	list = NULL;
	node1 = ft_lstnew("Node 1", sizeof("Node 1"));
	node2 = ft_lstnew("Node 2", sizeof("Node 2"));
	node3 = ft_lstnew("Node 3", sizeof("Node 3"));
	ft_lstadd_front(&list, node3);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node1);

	size = ft_lstsize(list);
	printf("Size: %d\n", size);

	ft_lstclear(&list, free);
	return (0);
}