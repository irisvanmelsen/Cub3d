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

bool	floodfill(t_map *map, char **dup_map, int y, int x)
{
	// if (y < 0 || x < 0)
	// 	return (false);
	// if (y >= map->length_y || x >= map->length_x)
	// 	return (true);
	// if (!valid_char(map->file_content[y][x]))
	// 	return (true);
	// if (map->file_content[y][x] == '1' || map->file_content[y][x] == PASSED)
	// 	return (false);
	// if (map->file_content[y][x] == '0')
	// {
	// 	map->file_content[y][x] = PASSED;
	// }
	// if (floodfill(map, dup_map, y + 1, x))
	// 	return (true);
	// if (floodfill(map, dup_map, y - 1, x))
	// 	return (true);
	// if (floodfill(map, dup_map, y, x + 1))
	// 	return (true);
	// if (floodfill(map, dup_map, y, x - 1))
	// 	return (true);
	return (true);
}

bool	map_init(t_cub3d *cub3d, t_map *map, int fd)
{
	int	i;

	ft_bzero((void *)map, sizeof(t_map));
	map->file_content = read_file(fd);
	if (!map->file_content)
		return (false);
	i = parse_elements_in_file(cub3d, map->file_content);
	if (!i)
		return (false);
	 if (!create_map(map, i))
	 	return (false);
	map->dup_content = create_dup_map(map);
	if (!map->dup_content)
		return (false);
	search_max_lengths(map->content, &map->length_x, &map->length_y);
	return (true);
}

bool	create_map(t_map *map, int i)
{
	int	j;
	int	size;

	j = 0;
	size = ptrarr_len((void **)&map->file_content[i]);
	map->content = ft_calloc(size + 1, sizeof(char *));
	if (!map->content)
		return (false);
	while (map->file_content[i])
	{
		map->content[j] = map->file_content[i];
		i++;
		j++;
	}
	return (true);
}

char	**read_file(int fd)
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
		if (free_line_if_empty(line))
			continue;
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

bool	free_line_if_empty(char *line)
{
	int i;

	i = skip_whitespace(line, 0);
	if (!line[i])
	{
		free(line);
		return (true);
	}
	return (false);
}
