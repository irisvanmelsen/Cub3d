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

void	raycast(void *param)
{
	t_nbrs	*nbrs;

	nbrs = (t_nbrs *)param;
	int	x;
	double cameraX;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * (x / (double)WIDTH) - 1;
		nbrs->mapX = nbrs->data->player.posX;
		nbrs->mapY = nbrs->data->player.posY;
		nbrs->rayDirX = nbrs->dirX + nbrs->planeX * cameraX;
		nbrs->rayDirY = nbrs->dirY + nbrs->planeY * cameraX;
		delta_dist(nbrs);
		calc_side_dist(nbrs);
		keep_lookin(nbrs);
		if (nbrs->side_hit == HORIZONTAL)
			nbrs->perp_dist = (nbrs->side_distX - nbrs->delta_distX);
		else
			nbrs->perp_dist = (nbrs->side_distY - nbrs->delta_distY);
		draw_line(nbrs, x); //
		x++;
	}
}

void	keep_lookin(t_nbrs *nbrs)
{
	while (1)
	{
		if (nbrs->side_distX < nbrs->side_distY)
		{
			nbrs->side_distX += nbrs->delta_distX;
			nbrs->mapX += nbrs->stepX;
			nbrs->side_hit = HORIZONTAL;
		}
		else
		{
			nbrs->side_distY += nbrs->delta_distY;
			nbrs->mapY += nbrs->stepY;
			nbrs->side_hit = VERTICAL;
		}
		if (nbrs->map->content[nbrs->mapY][nbrs->mapX] == '1') //removed out of bounds check
			break;
	}
}

void	delta_dist(t_nbrs *nbrs)
{
	if (nbrs->rayDirX == 0)
		nbrs->delta_distX = 1e30;
	else
		nbrs->delta_distX = fabs((float)1 / nbrs->rayDirX);
	if (nbrs->rayDirY == 0)
		nbrs->delta_distY = 1e30;
	else
		nbrs->delta_distY = fabs((float)1 / nbrs->rayDirY);
}


//calculates the side_distance, which is the distnace from the starting pos
// to the nearest gridline, as well as checking if we need the step adjustment
void	calc_side_dist(t_nbrs *nbrs)
{
	if (nbrs->rayDirX < 0)
	{
		nbrs->stepX = NEGATIVE;
		nbrs->side_distX = (nbrs->map->player_x - nbrs->mapX) * nbrs->delta_distX;
	}
	else
	{
		nbrs->stepX = POSITIVE;
		nbrs->side_distX =(nbrs->mapX + 1.0 - nbrs->map->player_x) * nbrs->delta_distX;
	}
	if (nbrs->rayDirY < 0)
	{
		nbrs->stepY = NEGATIVE;
		nbrs->side_distY =(nbrs->map->player_y - nbrs->mapY) * nbrs->delta_distY;
	}
	else
	{
		nbrs->stepY = POSITIVE;
		nbrs->side_distY =(nbrs->mapY + 1.0 - nbrs->map->player_y) * nbrs->delta_distY;
	}
}

void	draw_line(t_nbrs *nbrs, int x)
{
	long	draw_start;
	long	draw_end;
	int	lineheight = (int)HEIGHT / nbrs->perp_dist;

	draw_start = -lineheight / 2 + HEIGHT / 2;
	if(draw_start < 0)
		draw_start = 0;
	draw_end = lineheight / 2 + HEIGHT / 2;
	if(draw_end >= HEIGHT)
	  	draw_end = HEIGHT - 1;
	while (draw_start < draw_end)
	{
		mlx_put_pixel(nbrs->data->wall, x, draw_start, get_rgba(0, 255, 0, 255));
		draw_start++;
	}
}
