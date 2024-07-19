/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_displayed_cord.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:03:28 by shatan            #+#    #+#             */
/*   Updated: 2024/06/13 20:04:38 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	ft_get_displayed_cord(t_vec2 tile_size, t_itbl *itbl)
{
	t_vec2	ret;
	t_vec2	offset;

	offset = (t_vec2){0, 0};
	if (itbl->animation)
		offset = itbl->animation->offset;
	ret.x = 2 * itbl->cord.x * tile_size.x + offset.x + itbl->rel_cord.x;
	ret.y = 2 * itbl->cord.y * tile_size.y + offset.y + itbl->rel_cord.y;
	return (ret);
}
