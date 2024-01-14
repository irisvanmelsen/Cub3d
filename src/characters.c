/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:59:29 by iris              #+#    #+#             */
/*   Updated: 2024/01/15 00:40:43 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_characters(t_map *map)
{
	int	x;
	int	y;

	y = 6;
	while (map->content[y])
	{
		x = 0;
		while (map->content[y][x])
		{
			if (map->content[y][x] == 'N')
				map->n_count++;
			if (map->content[y][x] == 'S')
				map->s_count++;
			if (map->content[y][x] == 'E')
				map->e_count++;
			if (map->content[y][x] == 'W')
				map->w_count++;
			x++;
		}
		y++;
	}
	if (map->n_count > 1 || map->s_count > 1 
		|| map->e_count > 1 || map->w_count > 1)
		return (0);
	return (1);
}

// int	check_sides_wall(t_map *map)
// {
// 	int	y;

// 	y = 6;
// 	while (map->content[y])
// 	{
// 		printf("map->content[y]: %s\n", map->content[y]);
// 		// printf("map->content[y][ - 1]: %c\n", map->content[y][map->length_x - 1]);
// 		if (map->content[y][0] != '1' && map->content[y][0] != ' ')
// 			return (0);
// 		if (map->content[y][map->length_x - 1] != '1' && map->content[y][map->length_x - 1] != ' ')
// 			return (0);
// 		y++;
// 	}
// 	return (1);
// }

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

int	check_first_last_walls(t_map *map)
{
	int	x;

	x = 0;
	while (map->content[6][x])
	{
		if (map->content[6][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (map->content[map->length_y - 1][x])
	{
		if (map->content[map->length_y - 1][x] != '1' &&
			map->content[map->length_y - 1][x] != ' ' )
			return (0);
		x++;
	}
	return (1);
}
