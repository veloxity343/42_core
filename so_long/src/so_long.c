/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:44:08 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/11 17:27:41 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	while (line < game->heightmap)
	{
		if (game->map[line])
		{
			free(game->map[line]);
			game->map[line] = NULL;
		}
		line++;
	}
	if (game->map)
	{
		free(game->map);
		game->map = NULL;
	}
	if (game->mlxpointer)
	{
		free(game->mlxpointer);
		game->mlxpointer = NULL;
	}
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 64),
			(game.heightmap * 64), "so_long");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
