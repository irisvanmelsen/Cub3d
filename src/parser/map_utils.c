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

bool	top_bottom_check(char *map)
{
	size_t	x;

	x = 0;
	x = skip_whitespace(map, x);
	while (map[x])
	{
		if (map[x] != ' ' && map[x] != '1')
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
		if (map[y][x] != '1' || map[y][ft_strlen(map[y]) - 1] != '1')
			return (false);
		y++;
		x = 0;
	}
	y--;
	if (!top_bottom_check(map[y]))
		return (false);
	return (true);
}
