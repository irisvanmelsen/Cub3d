/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:01:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/02/02 16:17:23 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	position_setup(t_cub3d *cub3d)
{
	if (cub3d->player.direction == NO)
	{
		cub3d->player.position_x = 0;
		cub3d->player.position_y = -1;
	}
	if (cub3d->player.direction == SO)
	{
		cub3d->player.position_x = 0;
		cub3d->player.position_y = 1;
	}
	if (cub3d->player.direction == WE)
	{
		cub3d->player.position_x = -1;
		cub3d->player.position_y = 0;
	}
	if (cub3d->player.direction == EA)
	{
		cub3d->player.position_x = 1;
		cub3d->player.position_y = 0;
	}
}

void	cub3d_setup(t_cub3d *cub3d)
{
	position_setup(cub3d);
	mlx_setup(cub3d);

	
	
	
}
