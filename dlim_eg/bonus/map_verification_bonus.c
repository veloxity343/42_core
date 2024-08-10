/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:20:27 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:20:28 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_element_nbr(t_cha ch)
{
	if (ch.player != 1)
		got_error("PLAYER NUMBER IS INVALID\n");
	if (ch.collectible == 0)
		got_error("COLLECTIBLE NUMBER IS INVALID\n");
	if (ch.exit != 1)
		got_error("EXIT NUMBER IS INVALID\n");
	if (ch.enemy != 1)
		got_error("ENEMY PATROL NUMBER IS INVALID\n");
}

int	get_collectible_nbr(char **map, size_t lines_num)
{
	t_cha	ch;
	size_t	i;
	size_t	j;

	i = 0;
	initialize_all(&ch);
	while (++i < lines_num - 1)
	{
		j = -1;
		while (++j < ft_strlen(map[0]) - 2)
		{
			if (map[i][j] == 'C')
				ch.collectible++;
			if (map[i][j] == 'P')
				ch.player++;
			if (map[i][j] == 'E')
				ch.exit++;
			if (map[i][j] == 'I')
				ch.enemy++;
		}
	}
	check_element_nbr(ch);
	return (ch.collectible);
}

void	fill(char **tab, t_point cur, int *c, int *e)
{
	if (tab[cur.y][cur.x] == 'E')
		*e = 1;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'E')
		return ;
	if (tab[cur.y][cur.x] == 'C')
		*c += 1;
	tab[cur.y][cur.x] = '1';
	fill(tab, (t_point){cur.x - 1, cur.y}, c, e);
	fill(tab, (t_point){cur.x + 1, cur.y}, c, e);
	fill(tab, (t_point){cur.x, cur.y - 1}, c, e);
	fill(tab, (t_point){cur.x, cur.y + 1}, c, e);
}

void	flood_fill(char **map, t_point begin, int col)
{
	int	collectible;
	int	exit;

	collectible = 0;
	exit = 0;
	fill(map, begin, &collectible, &exit);
	if (collectible != col)
		got_error("INVALID PATH\n");
	if (exit != 1)
		got_error("INVALID PATH\n");
}

void	is_path_valid(char *file, t_sl sl)
{
	char	**map;
	t_point	p_position;

	map = parse_map_ber(file, sl.lines);
	if (!map)
		return ;
	p_position = query_coordinate(&sl, 'P');
	flood_fill(map, p_position, sl.fish_num);
	free_char_ss(map);
}
