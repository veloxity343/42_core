/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:56:00 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/04 11:01:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "trgb_colors.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
// # include "mlx.h"

# define IMG_SIZE 64

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}		t_positon;

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
void	ft_memset(void *b, int c, size_t length);
void	char_valid(t_complete *game);

#endif
