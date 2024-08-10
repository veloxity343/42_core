/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:18:38 by dlim-yua          #+#    #+#             */
/*   Updated: 2024/06/16 16:18:39 by dlim-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map_ber(char *file, int lines_num)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		got_error("OPEN FILE ERROR\n");
	map = (char **)malloc(sizeof(char *) * (lines_num + 1));
	if (!map)
		got_error("MEMORY ALLOCATION ERROR\n");
	i = 0;
	while (i < lines_num)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	check_line_num(char *file)
{
	int		fd;
	int		lines_num;
	char	*str;

	lines_num = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		got_error("OPEN FILE ERROR\n");
	str = get_next_line(fd);
	while (str)
	{
		lines_num++;
		free(str);
		str = get_next_line(fd);
	}
	if (lines_num == 0)
		got_error("EMPTY MAP FILE\n");
	close(fd);
	return (lines_num);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	free_char_ss(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
}

t_point	query_coordinate(t_sl *sl, char point)
{
	t_point	re;
	int		i;
	int		j;

	i = 0;
	while (sl->map[++i])
	{
		j = 0;
		while (sl->map[i][++j])
		{
			if (sl->map[i][j] == point)
			{
				re.x = j;
				re.y = i;
			}
		}
	}
	return (re);
}
