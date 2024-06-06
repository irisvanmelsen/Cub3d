/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmep.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:12:55 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/06 13:12:55 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


char	**_old_working_compare_maps(char **mm_array, char **mini_map, int player_x, int player_y)
{
	int	x;
	int	y;
	int	map_height;
	int	mm_height;

	y = 0;
	map_height = calc_height_minimap(mini_map);
	if (map_height < 5)
	{
		if (map_height == 4)
			mm_height = 4;
		else
			mm_height = map_height + 1;
	}
	else
		mm_height = 5;
	while (y < mm_height)
	{
		x = 0;
		while (x < 5)
		{
			if (player_y - 2 + y >= 0 && player_y - 2 + y  < MINI_HEIGHT && \
				player_x - 2 + x >= 0 && player_x - 2 + x <MINI_WIDTH)
			{
				if (mini_map[player_y - 2 + y][player_x - 2 + x] == '1')
					mm_array[y][x] = '1';
				else if (mini_map[player_y - 2 + y][player_x - 2 + x] == 'P')
					mm_array[y][x] = 'P';
				else
					mm_array[y][x] = '0';
			}
			else
				mm_array[y][x] = '#';
			x++;
		}
		y++;
	}
	mm_array[2][2] = 'P';
	return (mm_array);
}


char	**compare_maps(t_minimap *minimap, char **mm_array, t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	minimap->map_height = calc_height_minimap(cub3d->minimap->og_map);
	if (minimap->map_height < 5)
	{
		if (minimap->map_height == 4)
			minimap->mm_height = 4;
		else
			minimap->mm_height = minimap->map_height + 1;
	}
	else
		minimap->mm_height = 5;
	while (y < minimap->mm_height)
	{
		check_char_mm(mm_array, cub3d, y);
		y++;
	}
	mm_array[2][2] = 'P';
	return (mm_array);
}
