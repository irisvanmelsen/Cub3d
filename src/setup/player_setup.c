/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:22:02 by iris              #+#    #+#             */
/*   Updated: 2024/05/09 16:50:15 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//the dir is just the direction of th emap the player looks
// map starts at 0.0 in the top left corner so that's why it's always
// 1 or -1
//
// the plane is the camera plane that represents the screen and it always runs
// perpendicular to our dir

void	look_dirs_up_down(t_player *player, char dir_char)
{
	if (dir_char == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	if (dir_char == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
}

void	set_initial_look_dirs(t_player *player, char dir_char)
{
	look_dirs_up_down(player, dir_char);
	if (dir_char == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	if (dir_char == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}
