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

// void	player_setup(t_cub3d *cub3d)
// {
// 	if (cub3d->player.direction == NO)
// 		cub3d->player.view = PI / 2;
// 	if (cub3d->player.direction == SO)
// 		cub3d->player.view = PI + PI / 2;
// 	if (cub3d->player.direction == WE)
// 		cub3d->player.view = PI;
// 	if (cub3d->player.direction == EA)
// 		cub3d->player.direction = 0;
// }


//the dir is just the direction of th emap the player looks
// map starts at 0.0 in the top left corner so that's why it's always
// 1 or -1
//
// the plane is the camera plane that represents the screen and it always runs
// perpendicular to our dir
void	set_initial_look_dirs(t_player *player, char dir_char)
{
	if (dir_char == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	if (dir_char == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	if (dir_char == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	if (dir_char == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}
