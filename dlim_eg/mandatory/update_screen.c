/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:18:28 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:18:29 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xmp_to_images(t_sl *sl)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	sl->fish_img = mlx_xpm_file_to_image(sl->mlx, "assets/fish.xpm", &x, &y);
	sl->dc_img = mlx_xpm_file_to_image(sl->mlx, "assets/door_c.xpm", &x, &y);
	sl->do_img = mlx_xpm_file_to_image(sl->mlx, "assets/door_o.xpm", &x, &y);
	sl->nt_img = mlx_xpm_file_to_image(sl->mlx, "assets/nothing.xpm", &x, &y);
	sl->ri_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_right.xpm", &x, &y);
	sl->up_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_up.xpm", &x, &y);
	sl->brick_img = mlx_xpm_file_to_image(sl->mlx, "assets/wood.xpm", &x, &y);
	sl->le_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_left.xpm", &x, &y);
	sl->down_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_down.xpm", &x, &y);
}

void	load_window(t_sl *sl, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (sl->map[++i])
	{
		j = -1;
		while (sl->map[i][++j])
		{
			if (sl->map[i][j] == '1')
				mlx_put_image_to_window(sl->mlx, sl->win,
					sl->brick_img, j * 40, i * 40);
			if (sl->map[i][j] == '0')
				mlx_put_image_to_window(sl->mlx, sl->win,
					sl->nt_img, j * 40, i * 40);
			if (sl->map[i][j] == 'P')
				load_player(sl, keycode, i, j);
			if (sl->map[i][j] == 'C')
				load_collectible(sl, i, j);
			if (sl->map[i][j] == 'E')
				load_exit(sl, i, j);
		}
	}
}

void	load_player(t_sl *sl, int keycode, int i, int j)
{
	if (keycode == 13)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->up_img, j * 40, i * 40);
	if (keycode == 0)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->le_img, j * 40, i * 40);
	if (keycode == 1)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->down_img, j * 40, i * 40);
	if (keycode == 2)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->ri_img, j * 40, i * 40);
}

void	load_collectible(t_sl *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx, sl->win, sl->fish_img, j * 40, i * 40);
}

void	load_exit(t_sl *sl, int i, int j)
{
	if (sl->fish_num == 0)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->do_img, j * 40, i * 40);
	else
		mlx_put_image_to_window(sl->mlx, sl->win, sl->dc_img, j * 40, i * 40);
}
