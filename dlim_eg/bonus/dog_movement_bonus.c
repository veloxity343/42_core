/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_movement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:19:37 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:19:38 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_dog_around(t_sl *sl, t_point e)
{
	int	l;
	int	u;
	int	random_n1;
	int	random_n2;

	l = 1;
	u = 4;
	random_n1 = (rand() % (u - l + 1) + l);
	random_n2 = (rand() % (u - l + 1) + l);
	if (random_n1 == 1 && random_n2 == 1)
		dog_moveleft(sl, e);
	if (random_n1 == 2 && random_n2 == 2)
		dog_movedown(sl, e);
	if (random_n1 == 3 && random_n2 == 3)
		dog_moveright(sl, e);
	if (random_n1 == 4 && random_n2 == 4)
		dog_moveup(sl, e);
}

int	animation(t_sl *sl)
{
	t_point	enemy;

	enemy = query_coordinate(sl, 'I');
	move_dog_around(sl, enemy);
	load_window(sl, -1);
	return (1);
}
