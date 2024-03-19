/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_setup.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 20:22:02 by iris          #+#    #+#                 */
/*   Updated: 2024/02/02 21:26:14 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_setup(t_cub3d *cub3d)
{
	if (cub3d->player.direction == NO)
		cub3d->player.view = PI / 2;
	if (cub3d->player.direction == SO)
		cub3d->player.view = PI + PI / 2;
	if (cub3d->player.direction == WE)
		cub3d->player.view = PI;
	if (cub3d->player.direction == EA)
		cub3d->player.direction = 0;
}


//the dir is just the direction of th emap the player looks
// map starts at 0.0 in the top left corner so that's why it's always
// 1 or -1
//
// the plane is the camera plane that represents the screen and it always runs
// perpendicular to our dir
void	set_initial_look_dirs(t_cub3d *cub3d, t_raycast_data *raycast)
{
	if (cub3d->map->dir_char == 'N')
	{
		raycast->dirX = 0;
		raycast->dirY = -1;
		raycast->planeX = -0.66;
		raycast->planeY = 0;
	}
	if (cub3d->map->dir_char == 'E')
	{
		raycast->dirX = 1;
		raycast->dirY = 0;
		raycast->planeX = 0;
		raycast->planeY = -0.66;
	}
	if (cub3d->map->dir_char == 'S')
	{
		raycast->dirX = 0;
		raycast->dirY = 1;
		raycast->planeX = 0.66;
		raycast->planeY = 0;
	}
	if (cub3d->map->dir_char == 'W')
	{
		raycast->dirX = -1;
		raycast->dirY = 0;
		raycast->planeX = 0;
		raycast->planeY = 0.66;
	}
}
