/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   superseded_by_floodfill.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 23:59:29 by iris          #+#    #+#                 */
/*   Updated: 2024/01/15 00:40:43 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	check_characters(t_map *map) //superseded by only_one_player_symbol
{
	int	x;
	int	y;
	int	player_count;
	char c;

	y = 6;
	player_count = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			c = map->content[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (0);
	return (1);
}

int	check_sides_wall(t_map *map)
{
	int	y;
	int	line_length;

	y = 6;
	while (map->content[y])
	{
		line_length = ft_strlen(map->content[y]);
		if (line_length > 0 && (map->content[y][0] != '1' \
			&& map->content[y][0] != ' '))
			return (0);
		if (line_length > 0 && (map->content[y][line_length - 1] != '1' \
			&& map->content[y][line_length - 1] != ' '))
			return (0);
		y++;
	}
	return (1);
}

bool	check_first_last_walls(t_map *map)
{
	int	x;

	x = 0;
	while (map->content[6][x])
	{
		if (map->content[6][x] != '1' && map->content[6][x] != ' ')
			return (false);
		x++;
	}
	x = 0;
	while (map->content[map->length_y - 1][x])
	{
		if (map->content[map->length_y - 1][x] != '1' &&
			map->content[map->length_y - 1][x] != ' ' )
			return (false);
		x++;
	}
	return (true);
}

int	check_map_after_ff(char **map_after_ff)
{
	int	x;
	int	y;

	y = 0;
	while (map_after_ff[y])
	{
		x = 0;
		while (map_after_ff[y][x])
		{
			if (map_after_ff[y][x] != '1' && map_after_ff[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
