/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:48 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/11 15:17:32 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->player,
		width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, game->winpointer,
		game->collectable, width * 64, height * 64);
	game->collectables++;
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"assets/item.xpm", &i, &j);
}

void	handle_tile(t_complete *game, int height, int width)
{
	char	tile;

	tile = game->map[height][width];
	if (tile == '1')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->barrier, width * 64, height * 64);
	else if (tile == 'C')
		place_collectable(game, height, width);
	else if (tile == 'P')
		place_player(game, height, width);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->exit,
			width * 64, height * 64);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->floor,
			width * 64, height * 64);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	game->collectables = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			handle_tile(game, height, width);
			width++;
		}
		height++;
	}
}
