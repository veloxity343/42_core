/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:56:00 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/10 15:46:50 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "trgb_colors.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
// # include <mlx.h>
# include "../mlx/mlx.h"

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

void	place_collectable(t_complete *game, int height, int width);
void	place_player(t_complete *game, int height, int width);
void	handle_tile(t_complete *game, int height, int width);
void	adding_in_graphics(t_complete *game);
void	place_images_in_game(t_complete *game);
int		controls_working(int command, t_complete *game);
int		legal_move(t_complete *game, int i, int j);
int		keyboard_w_s(t_complete *game, int movement);
int		keyboard_a_d(t_complete *game, int movement);
int		width_of_map(char *string);
int		add_line(t_complete *game, char *line);
int		map_reading(t_complete *game, char **argv);
void	check_errors(t_complete *game);
int		exit_point(t_complete *game);
void	char_valid(t_complete *game);

#endif
