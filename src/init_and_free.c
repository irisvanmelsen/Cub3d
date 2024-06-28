/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_and_free.c                                    :+:    :+:            */
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

t_cub3d	*init_cub3d_data(void)
{
	t_cub3d	*cub3d;

	cub3d = ft_calloc(1, sizeof(t_cub3d));
	if (!cub3d)
		return (NULL);
	cub3d->map = ft_calloc(1, sizeof(t_map));
	cub3d->raycast = ft_calloc(1, sizeof(t_raycast_data));
	if (!cub3d->map || !cub3d->raycast)
	{
		free(cub3d->map);
		free(cub3d->raycast);
		free(cub3d);
		return (NULL);
	}
	return (cub3d);
}

static void	free_mlx_objects(t_cub3d *data)
{
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

//you can safely free NULL so the if statements not needed?
void	free_all(t_cub3d *data)
{
	if (data->map)
	{
		free_array((void *)data->map->file_content);
		free(data->map->content);
		free_array((void *)data->map->dup_content);
	}
	free(data->map);
	if (data->minimap)
	{
		free_array((void *)data->minimap->mm_array);
		if (data->minimap->image)
			mlx_delete_image(data->mlx, data->minimap->image);
		free(data->minimap);
	}
	free_mlx_objects(data);
	free(data->raycast);
	free(data);
}
