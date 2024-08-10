/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:20:54 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:20:55 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	xmp_to_images(t_sl *sl)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	sl->do_img = mlx_xpm_file_to_image(sl->mlx, "assets/door_o.xpm", &x, &y);
	sl->dog_img = mlx_xpm_file_to_image(sl->mlx, "assets/dog.xpm", &x, &y);
	sl->up_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_up.xpm", &x, &y);
	sl->down_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_down.xpm", &x, &y);
	sl->brick_img = mlx_xpm_file_to_image(sl->mlx, "assets/wood.xpm", &x, &y);
	sl->nt_img = mlx_xpm_file_to_image(sl->mlx, "assets/nothing.xpm", &x, &y);
	sl->le_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_left.xpm", &x, &y);
	sl->ri_img = mlx_xpm_file_to_image(sl->mlx, "assets/c_right.xpm", &x, &y);
	sl->fish_img = mlx_xpm_file_to_image(sl->mlx, "assets/fish.xpm", &x, &y);
	sl->dc_img = mlx_xpm_file_to_image(sl->mlx, "assets/door_c.xpm", &x, &y);
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
				load_other(sl, i, j, '1');
			if (sl->map[i][j] == '0')
				load_other(sl, i, j, '0');
			if (sl->map[i][j] == 'P')
				load_player(sl, keycode, i, j);
			if (sl->map[i][j] == 'C')
				load_collectible(sl, i, j);
			if (sl->map[i][j] == 'E')
				load_exit(sl, i, j);
			if (sl->map[i][j] == 'I')
				load_other(sl, i, j, 'I');
		}
	}
}
