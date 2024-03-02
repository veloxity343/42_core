#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char *data = argv[1];
		t_list *node = ft_lstnew(data);
		if (node)
		{
			printf("%s\n", (char *)node->content);
			printf("%p\n", node->next);
		}
		else
		{
			printf("Failed to create node.\n");
		}
		free(node);
	}
	return (0);
}