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
	// printf("data->pos.y: %f\n", data->player.pos.y);
	// load_textures_in(data); //not needed w new elements
}

void	init_cub3d_data(t_cub3d *cub3d, t_map *map, t_raycast_data *raycast)
{
	ft_bzero(cub3d, sizeof(cub3d));
	cub3d->map = map;
	cub3d->raycast = raycast;
}
