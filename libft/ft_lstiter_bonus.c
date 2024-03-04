/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:52:06 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 12:08:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*#include <stdio.h>

void	print_int(void *data)
{
	printf("%d ", *(int *)data);
}

int	main(void)
{
	t_list *list = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("example")));

	ft_lstiter(list, ft_toupper);
	ft_lstiter(list, print_int);
	printf("\n");

	ft_lstclear(&list, free);
	return (0);
}*/