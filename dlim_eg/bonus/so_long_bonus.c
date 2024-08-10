/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:20:37 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:20:38 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_sl	sl;

	sl.is_c = 0;
	sl.move_num = 0;
	sl.lines = 0;
	if (argc != 2)
		got_error("WRONG ARGUMENTS NUMBER\n");
	check_is_ber(argv[1]);
	sl.lines = check_line_num(argv[1]);
	sl.map = parse_map_ber(argv[1], sl.lines);
	check_is_rect(sl.map, sl.lines);
	check_walled(sl.map, sl.lines);
	check_valid_element(sl.map, sl.lines);
	sl.fish_num = get_collectible_nbr(sl.map, sl.lines);
	is_path_valid(argv[1], sl);
	main_ex(&sl);
}

void	main_ex(t_sl *sl)
{
	sl->mlx = mlx_init();
	sl->win = mlx_new_window(sl->mlx,
			ft_strlen(sl->map[sl->lines - 1]) * 40,
			sl->lines * 40, "so_long_bonus");
	xmp_to_images(sl);
	load_window(sl, 2);
	mlx_loop_hook(sl->mlx, animation, sl);
	mlx_hook(sl->win, 2, 1L << 0, &hook_key, sl);
	mlx_hook(sl->win, 17, 1L << 15, &finish_game, sl);
	mlx_loop(sl->mlx);
}

void	got_error(char *message)
{
	ft_printf("Error\n");
	ft_printf(message);
	exit(1);
}

int	finish_game(t_sl *sl)
{
	ft_printf("GAME OVER!\n");
	mlx_destroy_window(sl->mlx, sl->win);
	free_char_ss(sl->map);
	exit(0);
}

int	hook_key(int keycode, t_sl *sl)
{
	t_point	p;

	p = query_coordinate(sl, 'P');
	manage_move(sl, p, keycode);
	load_window(sl, keycode);
	return (1);
}
