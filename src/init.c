/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 16:59:07 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/03/19 16:59:07 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_raycast_data(t_raycast_data *raycast, t_cub3d *data)
{
	ft_bzero((void *)raycast, sizeof(*raycast));
	raycast->data = data;
	raycast->map = data->map;
	raycast->mapX = raycast->map->player_x;
	raycast->mapY = raycast->map->player_y;
	set_initial_look_dirs(&data->player, data->map->dir_char);
	data->player.pos.x = (double)raycast->map->player_x;
	data->player.pos.y = (double)raycast->map->player_y;
	data->player.data = data;
	data->raycast = raycast;
}

void	init_cub3d_data(t_cub3d *cub3d, t_map *map, t_raycast_data *raycast)
{
	ft_bzero(cub3d, sizeof(cub3d));
	cub3d->map = map;
	cub3d->raycast = raycast;
}
