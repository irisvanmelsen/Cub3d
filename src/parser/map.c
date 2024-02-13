/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 22:37:01 by iris          #+#    #+#                 */
/*   Updated: 2024/02/07 19:08:28 by ivan-mel      ########   odam.nl         */
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
	if (!valid_char(map->file_content[y][x]))
		return (true);
	if (map->file_content[y][x] == '1' || map->file_content[y][x] == PASSED)
		return (false);
	if (map->file_content[y][x] == '0')
	{
		map->file_content[y][x] = PASSED;
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

bool	map_init(t_map *map, int fd)
{
	ft_bzero((void *)map, sizeof(t_map));
	map->file_content = read_map(fd);
	if (!map->file_content)
		return (true);
	// create_map(map); disabled till it works
	map->dup_content = create_dup_map(map);
	if (!map->dup_content)
		return (false);
	search_max_lengths(map->file_content, &map->length_x, &map->length_y);
	return (true);
}

void	create_map(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = 6; //doesnt work cause could be more or less than 6, hceck for first 1
	// after all other elements
	i = 0;
	while (map->file_content[y])
	{
		x = 0;
		while (map->file_content[y][x])
		{
			map->content[i][x] = map->file_content[y][x];
			printf("map->content[i][x: %c", map->content[i][x]);
			x++;
		}
		y++;
		i++;
	}
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
