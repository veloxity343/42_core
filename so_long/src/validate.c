/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:53:13 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/11 17:01:38 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' && game->map[height][width] != '0'
		&& game->map[height][width] != 'P' && game->map[height][width] != 'E'
		&& game->map[height][width] != 'C' && game->map[height][width] != '\n')
	{
		ft_printf("\nError!\nCheck here: %c\n", game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	char_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		ft_printf("\nFFS, Error!\nCheck player, exit or collectable\n");
		exit_point(game);
	}
}
