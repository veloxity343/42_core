/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:20:11 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:20:12 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_walled(char **map, size_t lines_num)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < lines_num)
	{
		j = 0;
		if (i == 0 || i == lines_num - 1)
		{
			while (map[i][j] && j < ft_strlen(map[0]) - 1)
			{
				if (map[i][j] != '1')
					got_error("MAP IS NOT SURROUNDED WITH WALLS\n");
				j++;
			}
		}
		j = 0;
		while (map[i][j] && j < ft_strlen(map[0]) - 1)
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
				got_error("MAP IS NOT SURROUNDED WITH WALLS\n");
			j++;
		}
		i++;
	}
}

void	check_is_rect(char **map, size_t lines_num)
{
	size_t	first_line_len;
	size_t	i;

	i = 1;
	first_line_len = ft_strlen(map[0]);
	while (i < lines_num - 1)
	{
		if (ft_strlen(map[i]) != first_line_len)
			got_error("MAP IS NOT RECTANGULAR\n");
		i++;
	}
	if (ft_strlen(map[i]) != first_line_len - 1)
		got_error("MAP IS NOT RECTANGULAR\n");
}

void	check_is_ber(char *file)
{
	int		i;
	char	*extension;

	i = ft_strlen(file) - 4;
	extension = ft_substr(file, i, 4);
	if (ft_strcmp(".ber", extension) != 0)
	{
		free(extension);
		got_error("MAP FILE DOES NOT END WITH .ber\n");
	}
	free(extension);
}

void	check_valid_element(char **map, size_t lines_num)
{
	size_t	i;
	size_t	j;

	j = 1;
	i = 1;
	while (i < lines_num - 1)
	{
		j = 1;
		while (j < ft_strlen(map[0]) - 2)
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
					&& map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'I')
				got_error("MAP MUST INCLUDES ONLY 0, 1, P, C, E, I\n");
			j++;
		}
		i++;
	}
}

void	initialize_all(t_cha *ch)
{
	ch->collectible = 0;
	ch->player = 0;
	ch->exit = 0;
	ch->enemy = 0;
}
