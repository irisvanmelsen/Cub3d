/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 16:59:07 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/05/09 14:15:36 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

void	init_raycast_data(t_raycast_data *raycast, t_cub3d *data)
{
	ft_bzero((void *)raycast, sizeof(*raycast));
	raycast->data = data;
	set_initial_look_dirs(&data->player, data->map->dir_char);
	data->player.pos.x = (double)raycast->data->map->player_x;
	data->player.pos.y = (double)raycast->data->map->player_y;
	data->player.data = data;
	data->raycast = raycast;
}

void	init_cub3d_data(t_cub3d *cub3d, t_map *map, t_raycast_data *raycast)
{
	ft_bzero(cub3d, sizeof(cub3d));
	cub3d->map = map;
	cub3d->raycast = raycast;
}

void	free_all(t_cub3d *data)
{
	if (data->map->file_content)
		free_array((void *)data->map->file_content);
	if (data->map->content)
		free(data->map->content);
	if (data->map->dup_content)
		free_array((void *)data->map->dup_content);
	if (data->minimap->mm_array)
		free_array((void *)data->minimap->mm_array);
	if (data->minimap->image)
		mlx_delete_image(data->mlx, data->minimap->image);
	if (data->minimap)
		free(data->minimap);
	if (data->textures.north)
		mlx_delete_texture(data->textures.north);
	if (data->textures.east)
		mlx_delete_texture(data->textures.east);
	if (data->textures.south)
		mlx_delete_texture(data->textures.south);
	if (data->textures.west)
		mlx_delete_texture(data->textures.west);
	if (data->background)
		mlx_delete_image(data->mlx, data->background);
	if (data->wall)
		mlx_delete_image(data->mlx, data->wall);
}
