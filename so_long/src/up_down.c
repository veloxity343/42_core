/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:48:50 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/10 15:14:00 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	move_up(t_complete *game, int i, int j)
{
	j--;
	if (game->map[j][i] == '1')
		return (0);
	if (!legal_move(game, i, j))
		return (0);
	game->map[j + 1][i] = '0';
	return (1);
}

static int	move_down(t_complete *game, int i, int j)
{
	j++;
	if (game->map[j][i] == '1')
		return (0);
	if (!legal_move(game, i, j))
		return (0);
	game->map[j - 1][i] = '0';
	return (1);
}

int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	k = 0;
	if (movement == 13)
		k = move_up(game, i, j);
	else if (movement == 1)
		k = move_down(game, i, j);
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Left: %i\n", game->collectables);
	return (k);
}
