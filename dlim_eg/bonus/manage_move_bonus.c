/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:19:59 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:20:00 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	manage_move(t_sl *sl, t_point p, int keycode)
{
	if (keycode == 0)
		moveleft(sl, p);
	if (keycode == 1)
		movedown(sl, p);
	if (keycode == 2)
		moveright(sl, p);
	if (keycode == 13)
		moveup(sl, p);
	if (keycode == 53)
		finish_game(sl);
}

void	moveup(t_sl *sl, t_point p)
{
	if (sl->map[p.y - 1][p.x] != '1' && sl->map[p.y - 1][p.x] != 'E')
	{
		sl->move_num++;
		if (sl->map[p.y - 1][p.x] == 'C')
		{
			sl->fish_num--;
			sl->map[p.y - 1][p.x] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y - 1][p.x] == '0')
		{
			sl->map[p.y - 1][p.x] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y - 1][p.x] == 'I')
			finish_game(sl);
	}
	if (sl->map[p.y - 1][p.x] == 'E' && sl->fish_num == 0)
	{
		sl->move_num++;
		ft_printf("PLAYER WON!\n");
		mlx_destroy_window(sl->mlx, sl->win);
		exit(0);
	}
}

void	moveleft(t_sl *sl, t_point p)
{
	if (sl->map[p.y][p.x - 1] != '1' && sl->map[p.y][p.x - 1] != 'E')
	{
		sl->move_num++;
		if (sl->map[p.y][p.x - 1] == 'C' )
		{
			sl->fish_num--;
			sl->map[p.y][p.x - 1] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y][p.x - 1] == '0')
		{
			sl->map[p.y][p.x - 1] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y][p.x - 1] == 'I')
			finish_game(sl);
	}
	if (sl->map[p.y][p.x - 1] == 'E' && sl->fish_num == 0)
	{
		sl->move_num++;
		ft_printf("PLAYER WON!\n");
		mlx_destroy_window(sl->mlx, sl->win);
		exit(0);
	}
}

void	movedown(t_sl *sl, t_point p)
{
	if (sl->map[p.y + 1][p.x] != '1' && sl->map[p.y + 1][p.x] != 'E')
	{
		sl->move_num++;
		if (sl->map[p.y + 1][p.x] == 'C')
		{
			sl->fish_num--;
			sl->map[p.y + 1][p.x] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y + 1][p.x] == '0')
		{
			sl->map[p.y + 1][p.x] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y + 1][p.x] == 'I')
			finish_game(sl);
	}
	else if (sl->map[p.y + 1][p.x] == 'E' && sl->fish_num == 0)
	{
		sl->move_num++;
		ft_printf("PLAYER WON!\n");
		mlx_destroy_window(sl->mlx, sl->win);
		exit(0);
	}
}

void	moveright(t_sl *sl, t_point p)
{
	if (sl->map[p.y][p.x + 1] != '1' && sl->map[p.y][p.x + 1] != 'E')
	{
		sl->move_num++;
		if (sl->map[p.y][p.x + 1] == 'C')
		{
			sl->fish_num--;
			sl->map[p.y][p.x + 1] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y][p.x + 1] == '0')
		{
			sl->map[p.y][p.x + 1] = 'P';
			sl->map[p.y][p.x] = '0';
		}
		else if (sl->map[p.y][p.x + 1] == 'I')
			finish_game(sl);
	}
	else if (sl->map[p.y][p.x + 1] == 'E' && sl->fish_num == 0)
	{
		sl->move_num++;
		ft_printf("PLAYER WON!\n");
		mlx_destroy_window(sl->mlx, sl->win);
		exit(0);
	}
}
