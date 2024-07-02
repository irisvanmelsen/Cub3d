/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/25 13:29:40 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/25 13:29:40 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	top_bottom_check(char *line)
{
	size_t	x;

	x = 0;
	if (!line)
		return (false);
	x = skip_whitespace(line, x);
	while (line[x])
	{
		if (line[x] != ' ' && line[x] != '1')
			return (false);
		x++;
	}
	return (true);
}

bool	outer_walls_check(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	if (!top_bottom_check(map[y]))
		return (false);
	y++;
	while (map[y])
	{
		x = skip_whitespace(map[y], x);
		if (map[y][x] != '1' || map[y][ft_strlen(map[y]) - 1] != '1') //need while isnt whitespace length
			return (false);
		y++;
		x = 0;
	}
	y--;
	if (!top_bottom_check(map[y]))
		return (false);
	return (true);
}

bool	is_str_in_bounds(char *str, int i)
{
	if (!str)
		return (false);
	if (i < 0 || i > (int)ft_strlen(str))
		return (false);
	return (true);
}

bool	is_map_in_bounds(char **map, int y, int x)
{
	if (!map)
		return (false);
	if (y < 0 || y > ptrarr_len((void **)map))
		return (false);
	if (x < 0 || x > (int)ft_strlen(map[y]))
		return (false);
	return (true);
}
