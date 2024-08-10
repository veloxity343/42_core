/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:41:16 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/03/03 14:41:18 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*#include <stdio.h>
int	main()
{
	t_list	*node = malloc(sizeof(t_list));

	node->content = malloc(3);
	strcpy((char *)node->content, "14");
	node->next = NULL;

	ft_lstdelone(node, &free);

	printf("%s", node->content);
	return (0);
}*/