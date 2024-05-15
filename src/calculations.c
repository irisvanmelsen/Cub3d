/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:05:00 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/05/09 14:13:19 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief calcs the distance the raydir has from one edge of a tile to the next
 *since we only care about the ratio between x and y we can simplify it to just
 this, 0 will always be the shortest so that's why it gets the max value
 * @param raydir
 * @return the delta distance for both x and Y
 */

t_vector	calc_delta_dist(t_vector raydir)
{
	t_vector	delta_dist;

	if (raydir.x == 0)
		delta_dist.x = 1e30;
	else
		delta_dist.x = fabs((float)1 / raydir.x);
	if (raydir.y == 0)
		delta_dist.y = 1e30;
	else
		delta_dist.y = fabs((float)1 / raydir.y);
	return (delta_dist);
}

double	calc_perp_dist_and_wallx(t_raycast_data *raycast, t_player *player)
{
	double	wallx;

	if (raycast->side_hit == HORIZONTAL)
	{
		raycast->perp_dist = (raycast->side_dist.x - raycast->delta_dist.x);
		wallx = player->pos.y + raycast->perp_dist * raycast->raydir.y;
	}
	else
	{
		raycast->perp_dist = (raycast->side_dist.y - raycast->delta_dist.y);
		wallx = player->pos.x + raycast->perp_dist * raycast->raydir.x;
	}
	return (wallx -= floor(wallx));
}

//calculates the side_distance, which is the distnace from the starting pos
// to the nearest gridline, as well as checking if we need the step adjustment

void	calc_side_dist(t_raycast_data *raycast, t_player *player) //take raydir
{
	if (raycast->raydir.x < 0)
	{
		raycast->map_stepdir.x = NEGATIVE;
		raycast->side_dist.x = (player->pos.x - raycast->maptile.x) * \
		raycast->delta_dist.x;
	}
	else
	{
		raycast->map_stepdir.x = POSITIVE;
		raycast->side_dist.x = (raycast->maptile.x + 1.0 - player->pos.x) * \
		raycast->delta_dist.x;
	}
	if (raycast->raydir.y < 0)
	{
		raycast->map_stepdir.y = NEGATIVE;
		raycast->side_dist.y = (player->pos.y - raycast->maptile.y) * \
		raycast->delta_dist.y;
	}
	else
	{
		raycast->map_stepdir.y = POSITIVE;
		raycast->side_dist.y = (raycast->maptile.y + 1.0 - player->pos.y) * \
		raycast->delta_dist.y;
	}
}
