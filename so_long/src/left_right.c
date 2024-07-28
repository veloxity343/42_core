/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:47:04 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/28 12:51:22 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	move_left(t_complete *game, int i, int j)
{
	i--;
	if (game->map[j][i] == '1')
		return (0);
	if (!right_move(game, i, j))
		return (0);
	game->map[j][i + 1] = '0';
	return (1);
}

static int	move_right(t_complete *game, int i, int j)
{
	i++;
	if (game->map[j][i] == '1')
		return (0);
	if (!right_move(game, i, j))
		return (0);
	game->map[j][i - 1] = '0';
	return (1);
}

int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	k = 0;
	if (movement == 0)
		k = move_left(game, i, j);
	else if (movement == 2)
		k = move_right(game, i, j);
	printf("Steps Taken: %i\n", game->counter);
	printf("Collectables Remaining: %i\n", game->collectables);
	return (k);
}
