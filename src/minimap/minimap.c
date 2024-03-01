/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:22:54 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/03/01 18:06:16 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	init_minimap(t_cub3d *cub3d)
{
		cub3d->minimap->scaler = MINI_WIDTH / 6;
}

bool	boundary_check(char **mm_array, int player_y, int player_x)
{
	if (player_y > 6 || player_x > 6)
		return(false);
	if (player_y < 0 || player_x < 0)
		return(false);
}

char	**compare_maps(t_cub3d *cub3d, char **mm_array)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 6)
	{
		while (x < 6)
		{
			if (boundary_check(mm_array, cub3d->map->player_y, \
				cub3d-map->player_x) == true)
				mm_array[][];
			if (cub3d->map[cub3d->map->player_y + y] \
				[cub3d->map->player_x] == '0')
					mm_array[y - 2][x - 2] = '0';
			else if (cub3d->map[cub3d->map->player_y + y] \
				[cub3d->map->player_x + x] == '1')
					mm_array[y - 2][x - 2] = '1';
			else if (cub3d->map[cub3d->map->player_y + y] \
				[cub3d->map->player_x + x] == ' ')
					mm_array[y - 2][x - 2] = '1';
			x++;
		}
		y++;
	}
	mm_array[2][2] == 'P';
	return (mm_array);
}

char	**setup_minimap_arr(char **mm_array)
{
	int	i;

	i = 0;
	mm_array = ft_calloc(6, sizeof(char *));
	if (!mm_array)
		return (print_error(ERROR_ALLOCATION));
	while (i < 5)
	{
		mm_array[i] = ft_calloc(6, sizeof(char));
		if (!mm_array[i])
			return (print_error(ERROR_ALLOCATION));
		i++;
	}
	mm_array[i] = '\0';
	return (mm_array);
}

void	fill_wall_backgr(char **mm_array)
{
	int	x;
	int	y;

	while (mm_array[y])
	{
		y = 0;
		while (mm_array[x][y])
		{
			if (mm_array[y][x] == '0')
			
			if (mm_array[y][x] == '1')

			if (mm_array[y][x] == 'P')
		}
	}
}

void	start_minimap(t_cub3d *cub3d)
{
	char	**mm_array;
	
	init_minimap(cub3d);
	if (!cub3d->minimap->image)
	{
		cub3d->minimap->image = mlx_new_image(cub3d->minimap->mlx, MINI_WIDTH, MINI_HEIGHT);
		if (!cub3d->minimap->image)
			return (print_error(ERROR_IMAGE));
	}
	mm_array = setup_minimap_arr(mm_array);
	mm_array = compare_maps(cub3d, mm_array);
	fill_wall_backgr();
}