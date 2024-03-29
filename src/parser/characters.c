/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:59:29 by iris              #+#    #+#             */
/*   Updated: 2024/03/20 21:59:40 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	only_one_player_symbol(t_map *map)
{
	int	x;
	int	y;
	int	player_count;

	y = 0;
	player_count = 0;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (is_player_char(map->content[y][x]))
			{
				player_count++;
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (0);
	return (1);
}

void	find_max_lengths(char **map, int *length_x, int *length_y)
{
	int	i;
	int	max_length;
	int	current_len;

	i = 0;
	max_length = 0;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (max_length < current_len)
			max_length = current_len;
		i++;
	}
	*length_x = max_length;
	*length_y = i;
}

bool	is_player_char(char c)
{
	if ((c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (true);
	return (false);
}

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
