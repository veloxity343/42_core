/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog_movement_direct_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:19:47 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:19:48 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_dog(t_sl *sl, t_point p, int is_c, char c)
{
	sl->is_c = is_c;
	sl->map[p.y][p.x] = c;
	if (sl->dog_direct == 1)
		sl->map[p.y][p.x - 1] = 'I';
	if (sl->dog_direct == 2)
		sl->map[p.y][p.x + 1] = 'I';
	if (sl->dog_direct == 3)
		sl->map[p.y - 1][p.x] = 'I';
	if (sl->dog_direct == 4)
		sl->map[p.y + 1][p.x] = 'I';
}

void	dog_moveup(t_sl *sl, t_point p)
{
	sl->dog_direct = 3;
	if (sl->map[p.y - 1][p.x] != '1' && sl->map[p.y - 1][p.x] != 'E' &&
			sl->map[p.y - 1][p.x] != 'P')
	{
		if (sl->is_c == 1)
		{
			if (sl->map[p.y - 1][p.x] == 'C')
				move_dog(sl, p, 1, 'C');
			else if (sl->map[p.y - 1][p.x] == '0')
				move_dog(sl, p, 0, 'C');
		}
		if (sl->is_c == 0)
		{
			if (sl->map[p.y - 1][p.x] == '0')
				move_dog(sl, p, 0, '0');
			else if (sl->map[p.y - 1][p.x] == 'C')
				move_dog(sl, p, 1, '0');
		}
	}
	else if (sl->map[p.y - 1][p.x] == 'P')
		finish_game(sl);
}

void	dog_moveleft(t_sl *sl, t_point p)
{
	sl->dog_direct = 1;
	if (sl->map[p.y][p.x - 1] != '1' && sl->map[p.y][p.x - 1] != 'E' &&
			sl->map[p.y][p.x - 1] != 'P')
	{
		if (sl->is_c == 1)
		{
			if (sl->map[p.y][p.x - 1] == 'C')
				move_dog(sl, p, 1, 'C');
			else if (sl->map[p.y][p.x - 1] == '0')
				move_dog(sl, p, 0, 'C');
		}
		if (sl->is_c == 0)
		{
			if (sl->map[p.y][p.x - 1] == '0')
				move_dog(sl, p, 0, '0');
			else if (sl->map[p.y][p.x - 1] == 'C')
				move_dog(sl, p, 1, '0');
		}
	}
	else if (sl->map[p.y][p.x - 1] == 'P')
		finish_game(sl);
}

void	dog_movedown(t_sl *sl, t_point p)
{
	sl->dog_direct = 4;
	if (sl->map[p.y + 1][p.x] != '1' && sl->map[p.y + 1][p.x] != 'E' &&
			sl->map[p.y + 1][p.x] != 'P')
	{
		if (sl->is_c == 1)
		{
			if (sl->map[p.y + 1][p.x] == 'C')
				move_dog(sl, p, 1, 'C');
			else if (sl->map[p.y + 1][p.x] == '0')
				move_dog(sl, p, 0, 'C');
		}
		if (sl->is_c == 0)
		{
			if (sl->map[p.y + 1][p.x] == '0')
				move_dog(sl, p, 0, '0');
			else if (sl->map[p.y + 1][p.x] == 'C')
				move_dog(sl, p, 1, '0');
		}
	}
	else if (sl->map[p.y + 1][p.x] == 'P')
		finish_game(sl);
}

void	dog_moveright(t_sl *sl, t_point p)
{
	sl->dog_direct = 2;
	if (sl->map[p.y][p.x + 1] != '1' && sl->map[p.y][p.x + 1] != 'E' &&
			sl->map[p.y][p.x + 1] != 'P')
	{
		if (sl->is_c == 1)
		{
			if (sl->map[p.y][p.x + 1] == 'C')
				move_dog(sl, p, 1, 'C');
			else if (sl->map[p.y][p.x + 1] == '0')
				move_dog(sl, p, 0, 'C');
		}
		if (sl->is_c == 0)
		{
			if (sl->map[p.y][p.x + 1] == '0')
				move_dog(sl, p, 0, '0');
			else if (sl->map[p.y][p.x + 1] == 'C')
				move_dog(sl, p, 1, '0');
		}
	}
	else if (sl->map[p.y][p.x + 1] == 'P')
		finish_game(sl);
}
