/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 22:37:01 by iris          #+#    #+#                 */
/*   Updated: 2024/01/15 00:24:35 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// kan zelfs makkelijker, zonder floodfill?

char	**floodfill(char **content, int y, int x)
{
	if (y >= 0 && x >= 0 && content && content[y] && content[y][x] \
		&& content[y][x] != '1')
	{
		if (content[y][x] == 'N' || content[y][x] == 'S'
		|| content[y][x] == 'E' || content[y][x] == 'W'
		|| content[y][x] == '0' || content[y][x] == ' ')
			content[y][x] = '1';
		else
			return (content);
		floodfill(content, y, x + 1);
		floodfill(content, y, x - 1);
		floodfill(content, y + 1, x);
		floodfill(content, y - 1, x);
	}
	return (content);
}

int	count_lines(char **content)
{
	int	i;

	i = 0;
	while (content[i] != NULL)
		i++;
	return (i);
}

void	map_init(t_map *map)
{
	map->length_y = count_lines(map->content);
	map->player_x = 0;
	map->player_y = 0;
	map->n_count = 0;
	map->s_count = 0;
	map->e_count = 0;
	map->w_count = 0;
}

char	**read_map(int fd)
{
	char	*map;
	char	*line;
	char	**result;

	line = NULL;
	map = NULL;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = ft_strjoin_free(map, line);
		if (!map)
			return (NULL);
	}
	if (!map)
		return (NULL);
	result = ft_split(map, '\n');
	free (map);
	if (!result)
		return (NULL);
	return (result);
}
