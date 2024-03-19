/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 18:06:51 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/03/01 18:06:51 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster(void *param)
{
	t_raycast_data	*raycast;

	raycast = (t_raycast_data *)param;
	int	x;
	double cameraX;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * (x / (double)WIDTH) - 1;
		raycast->mapX = (int)raycast->data->player.posX;
		raycast->mapY = (int)raycast->data->player.posY;
		raycast->rayDirX = raycast->dirX + raycast->planeX * cameraX;
		raycast->rayDirY = raycast->dirY + raycast->planeY * cameraX;
		delta_dist(raycast);
		calc_side_dist(raycast);
		keep_lookin(raycast);
		if (raycast->side_hit == HORIZONTAL)
			raycast->perp_dist = (raycast->side_distX - raycast->delta_distX);
		else
			raycast->perp_dist = (raycast->side_distY - raycast->delta_distY);
		draw_line(raycast, x);
		x++;
	}
}

void	keep_lookin(t_raycast_data *raycast)
{
	while (1)
	{
		if (raycast->side_distX < raycast->side_distY)
		{
			raycast->side_distX += raycast->delta_distX;
			raycast->mapX += raycast->stepX;
			raycast->side_hit = HORIZONTAL;
		}
		else
		{
			raycast->side_distY += raycast->delta_distY;
			raycast->mapY += raycast->stepY;
			raycast->side_hit = VERTICAL;
		}
		if (raycast->map->content[raycast->mapY][raycast->mapX] == '1') //removed out of bounds check
			break;
	}
}

void	delta_dist(t_raycast_data *raycast)
{
	if (raycast->rayDirX == 0)
		raycast->delta_distX = 1e30;
	else
		raycast->delta_distX = fabs((float)1 / raycast->rayDirX);
	if (raycast->rayDirY == 0)
		raycast->delta_distY = 1e30;
	else
		raycast->delta_distY = fabs((float)1 / raycast->rayDirY);
}


//calculates the side_distance, which is the distnace from the starting pos
// to the nearest gridline, as well as checking if we need the step adjustment
void	calc_side_dist(t_raycast_data *raycast)
{
	if (raycast->rayDirX < 0)
	{
		raycast->stepX = NEGATIVE;
		raycast->side_distX = (raycast->map->player_x - raycast->mapX) * raycast->delta_distX;
	}
	else
	{
		raycast->stepX = POSITIVE;
		raycast->side_distX =(raycast->mapX + 1.0 - raycast->map->player_x) * raycast->delta_distX;
	}
	if (raycast->rayDirY < 0)
	{
		raycast->stepY = NEGATIVE;
		raycast->side_distY =(raycast->map->player_y - raycast->mapY) * raycast->delta_distY;
	}
	else
	{
		raycast->stepY = POSITIVE;
		raycast->side_distY =(raycast->mapY + 1.0 - raycast->map->player_y) * raycast->delta_distY;
	}
}

void	draw_line(t_raycast_data *raycast, int x)
{
	long	draw_start;
	long	draw_end;
	int	lineheight = (int)HEIGHT / raycast->perp_dist;

	draw_start = -lineheight / 2 + HEIGHT / 2;
	if(draw_start < 0)
		draw_start = 0;
	draw_end = lineheight / 2 + HEIGHT / 2;
	if(draw_end >= HEIGHT)
	  	draw_end = HEIGHT - 1;
	while (draw_start < draw_end)
	{
		mlx_put_pixel(raycast->data->wall, x, draw_start, get_rgba(0, 255, 0, 255));
		draw_start++;
	}
}
