/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:51:27 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 11:51:27 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

/*#include <stdio.h>

int	main(void)
{
	t_list *list = NULL;

	ft_lstadd_front(&list, ft_lstnew("Node 3", 7));
	ft_lstadd_front(&list, ft_lstnew("Node 2", 7));
	ft_lstadd_front(&list, ft_lstnew("Node 1", 7));

	t_list *last = ft_lstlast(list);

	if (last)
	{
		printf("%s\n", (char *)last->content);
	}

	ft_lstclear(&list, free);
	return (0);
}*/