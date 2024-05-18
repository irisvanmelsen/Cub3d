/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:22:54 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/05/18 19:16:22 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_cub3d *cub3d)
{
	cub3d->minimap->cub3d = cub3d;
	cub3d->minimap->mlx = cub3d->mlx;
	cub3d->minimap->scaler = MINI_WIDTH / 8;
	cub3d->minimap->og_map = cub3d->map->content;
}

int	calc_height_minimap(char **mini_map)
{
	int	y;

	y = 0;
	while (mini_map[y])
		y++;
	return (y);
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
		check_char_mm(cub3d->minimap, mm_array, cub3d, y);
		y++;
	}
	mm_array[2][2] = 'P';
	return (mm_array);
}

char	**setup_minimap_arr(void)
{
	int		i;
	char	**mm_array;

	i = 0;
	mm_array = ft_calloc(6, sizeof(char *));
	if (!mm_array)
	{
		print_error(get_error_name(ERROR_ALLOCATION));
		return (NULL);
	}
	while (i < 5)
	{
		mm_array[i] = ft_calloc(6, sizeof(char));
		if (!mm_array[i])
		{
			print_error(get_error_name(ERROR_ALLOCATION));
			return (NULL);
		}
		i++;
	}
	mm_array[5] = NULL;
	return (mm_array);
}

bool	start_minimap(t_cub3d *cub3d)
{
	cub3d->minimap = ft_calloc(1, sizeof(t_minimap));
	if (!cub3d->minimap)
		print_error(get_error_name(ERROR_ALLOCATION));
	init_minimap(cub3d);
	if (!cub3d->minimap->image)
	{
		cub3d->minimap->image = mlx_new_image(cub3d->minimap->mlx, \
		MINI_WIDTH, MINI_HEIGHT);
		if (!cub3d->minimap->image)
			return (print_error(get_error_name(ERROR_IMAGE)));
	}
	if (!cub3d->minimap->border)
		setup_border(cub3d->minimap);
	cub3d->minimap->mm_array = setup_minimap_arr();
	cub3d->minimap->mm_array = compare_maps(cub3d->minimap, cub3d->minimap->mm_array, cub3d);
	fill_wall_backgr(cub3d->minimap->mm_array, cub3d->minimap);
	return (true);
}
