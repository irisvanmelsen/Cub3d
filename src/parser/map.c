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

#include "cub3d.h"

bool	map_init(t_map *map, int map_start_index)
{
	 if (!create_map(map, map_start_index) || !create_dup_map(map))
	 	return (print_error(MAP_ALLOC_FAIL));
	find_max_lengths(map->content, &map->length_x, &map->length_y);
	if (!only_one_player_symbol(map))
		return (print_error(get_error_name(ERROR_CHARACTER)));
	print_2d_charray(map->content);
	if (!floodfill(map->dup_content, map->player_y, map->player_x))
		return (print_error(FLOOD_FAIL));
	return (true);
}

bool	floodfill(char **dup_map, int y, int x)
{
	//write check for if player is outside the walls
	if (y < 0 || x < 0)
		return (true);
	if (!dup_map[y] || x >= (int)ft_strlen(dup_map[y]))
		return (true);
	if (!valid_char(dup_map[y][x]))
		return (false);
	if (dup_map[y][x] == '1' || dup_map[y][x] == PASSED)
		return (true);
	dup_map[y][x] = PASSED;
	if (!floodfill(dup_map, y + 1, x))
		return (false);
	if (!floodfill(dup_map, y - 1, x))
		return (false);
	if (!floodfill(dup_map, y, x + 1))
		return (false);
	if (!floodfill(dup_map, y, x - 1))
		return (false);
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
	map->content[j] = NULL;
	return (true);
}

bool	create_dup_map(t_map *map)
{
	int	i;

	i = 0;
	map->dup_content = (char **)ft_calloc((ptrarr_len((void **)map->content) + 1), \
						sizeof(char *));
	if (!map->dup_content)
		return (false);
	while (map->content[i])
	{
		map->dup_content[i] = ft_strdup(map->content[i]);
		if (!map->dup_content[i])
			return (false);
		i++;
	}
	map->dup_content[i] = NULL;
	return (true);
}
