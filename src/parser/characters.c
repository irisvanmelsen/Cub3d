/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   characters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 23:59:29 by iris          #+#    #+#                 */
/*   Updated: 2024/01/26 17:02:32 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_characters(t_map *map)
{
	int		x;
	int		y;
	int		player_count;
	char	c;

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

void	search_max_lengths(char **map, int *length_x, int *length_y)
{
	int	i;
	int	length;
	int	length_next;

	i = 0;
	length = 0;
	length_next = 0;
	while (map[i])
	{
		length_next = ft_strlen(map[i]);
		if (length < length_next)
			length = length_next;
		i++;
	}
	*length_x = length;
	*length_y = i;
}

bool	is_player_char(char c)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (true);
	return (false);
}

bool	find_player_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (is_player_char(map->content[y][x]))
			{
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (!map->player_x || !map->player_y)
		return (false);
	return (true);
}
