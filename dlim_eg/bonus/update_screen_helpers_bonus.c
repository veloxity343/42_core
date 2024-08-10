/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen_helpers_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:21:02 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:21:05 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_exit(t_sl *sl, int i, int j)
{
	if (sl->fish_num == 0)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->do_img, j * 40, i * 40);
	else
		mlx_put_image_to_window(sl->mlx, sl->win, sl->dc_img, j * 40, i * 40);
}

void	load_player(t_sl *sl, int keycode, int i, int j)
{
	char	*a;
	char	*b;

	if (keycode == 13)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->up_img, j * 40, i * 40);
	if (keycode == 0)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->le_img, j * 40, i * 40);
	if (keycode == 1)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->down_img, j * 40, i * 40);
	if (keycode == 2)
		mlx_put_image_to_window(sl->mlx, sl->win, sl->ri_img, j * 40, i * 40);
	b = ft_itoa(sl->move_num);
	a = ft_strjoin("moves - ", b);
	mlx_string_put(sl->mlx, sl->win, 10, 10, 0xFFFFFF, a);
	free(a);
	free(b);
}

void	load_other(t_sl *sl, int i, int j, char e)
{
	if (e == '0')
		mlx_put_image_to_window(sl->mlx, sl->win,
			sl->nt_img, j * 40, i * 40);
	if (e == '1')
		mlx_put_image_to_window(sl->mlx, sl->win,
			sl->brick_img, j * 40, i * 40);
	if (e == 'I')
		mlx_put_image_to_window(sl->mlx, sl->win,
			sl->dog_img, j * 40, i * 40);
}

void	load_collectible(t_sl *sl, int i, int j)
{
	mlx_put_image_to_window(sl->mlx, sl->win, sl->fish_img, j * 40, i * 40);
}
