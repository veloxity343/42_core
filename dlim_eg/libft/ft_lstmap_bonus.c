/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:45:48 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/03/03 16:45:49 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	out = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (out)
			{
				new = out->next;
				del(out->content);
				free(out);
				out = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&out, new);
		lst = lst->next;
	}
	return (out);
}
