/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:20:45 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:20:46 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_cha
{
	int	player;
	int	collectible;
	int	exit;
	int	enemy;
}	t_cha;

typedef struct s_sl
{
	char	**map;
	void	*mlx;
	void	*win;
	size_t	lines;
	int		move_num;
	int		fish_num;
	void	*brick_img;
	void	*nt_img;
	void	*dc_img;
	void	*do_img;
	void	*le_img;
	void	*ri_img;
	void	*up_img;
	void	*down_img;
	void	*fish_img;
	void	*dog_img;
	int		is_c;
	int		dog_direct;
}	t_sl;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	check_is_ber(char *file);
void	check_is_rect(char **map, size_t lines_num);
void	check_walled(char **map, size_t lines_num);
void	check_valid_element(char **map, size_t lines_num);
int		animation(t_sl *sl);
void	moveleft(t_sl *sl, t_point p);
void	moveup(t_sl *sl, t_point p);
void	moveright(t_sl *sl, t_point p);
void	movedown(t_sl *sl, t_point p);
int		check_line_num(char *file);
char	**parse_map_ber(char *file, int lines_num);
t_point	query_coordinate(t_sl *sl, char point);
int		ft_strcmp(char *s1, char *s2);
void	xmp_to_images(t_sl *sl);
void	load_window(t_sl *sl, int keycode);
void	load_player(t_sl *sl, int keycode, int i, int j);
void	got_error(char *message);
int		hook_key(int keycode, t_sl *sl);
int		finish_game(t_sl *sl);
void	check_element_nbr(t_cha chas);
void	load_collectible(t_sl *sl, int i, int j);
void	move_dog_around(t_sl *sl, t_point e);
void	move_dog(t_sl *sl, t_point p, int tmp, char c);
void	dog_moveleft(t_sl *sl, t_point p);
void	dog_moveright(t_sl *sl, t_point p);
void	dog_moveup(t_sl *sl, t_point p);
void	dog_movedown(t_sl *sl, t_point p);
void	manage_move(t_sl *sl, t_point p, int keycode);
void	load_exit(t_sl *sl, int i, int j);
void	load_other(t_sl *sl, int i, int j, char e);
void	main_ex(t_sl *sl);
void	initialize_all(t_cha *all);
int		get_collectible_nbr(char **map, size_t lines_num);
void	is_path_valid(char *file, t_sl sl);
void	free_char_ss(char **str);

#endif
