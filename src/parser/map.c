/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:37:01 by iris              #+#    #+#             */
/*   Updated: 2024/02/02 13:14:38 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#define PASSED '2'
#define VALID_CHARS "10NSEW2"

bool	valid_char(char c)
{
	int	i;

	i = 0;
	while (VALID_CHARS[i])
	{
		if (c == VALID_CHARS[i])
			return (true);
		i++;
	}
	return (false);
}

bool	floodfill(t_map *map, char **dup_map, int y, int x)
{
	if (y < 0 || x < 0)
		return (false);
	if (y >= map->length_y || x >= map->length_x)
		return (true);
	if (!valid_char(map->content[y][x]))
		return (true);
	if (map->content[y][x] == '1' || map->content[y][x] == PASSED)
		return (false);
	if (map->content[y][x] == '0')
	{
		map->content[y][x] = PASSED;
	}
	if (floodfill(map, dup_map, y + 1, x))
		return (true);
	if (floodfill(map, dup_map, y - 1, x))
		return (true);
	if (floodfill(map, dup_map, y, x + 1))
		return (true);
	if (floodfill(map, dup_map, y, x - 1))
		return (true);
	return (false);
}

void	map_init(t_map *map)
{
	search_max_lengths(map->content, &map->length_x, &map->length_y);
	map->player_x = 0;
	map->player_y = 0;
	map->player_count = 0;
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
