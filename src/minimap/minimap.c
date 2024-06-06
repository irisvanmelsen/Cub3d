/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 13:22:54 by ivan-mel      #+#    #+#                 */
/*   Updated: 2024/05/18 19:16:22 by iris          ########   odam.nl         */
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

char	**compare_maps(t_minimap *minimap, char **mm_array, t_cub3d *cub3d)
{
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

void	mm_update(t_cub3d *cub3d, t_minimap *minimap)
{
	minimap->mm_array = compare_maps(minimap, \
		minimap->mm_array, cub3d);
	draw_mm(minimap->mm_array, minimap);
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
	cub3d->minimap->mm_array = compare_maps(cub3d->minimap, \
	cub3d->minimap->mm_array, cub3d);
	fill_wall_backgr(cub3d->minimap->mm_array, cub3d->minimap);
	return (true);
}
