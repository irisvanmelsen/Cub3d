/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:06:51 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/04/12 22:15:15 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vector	calc_delta_dist(t_vector raydir);
static void	calc_side_dist(t_raycast_data *raycast, t_player *player);

void	get_side_texture(t_raycast_data *ray, t_textures *texture)
{
	if (ray->side_hit == VERTICAL)
	{
		if (ray->raydir.y > 0)
			texture->used_tex = texture->north_text;
		else
			texture->used_tex = texture->south_text;
	}
	else if (ray->side_hit == HORIZONTAL)
	{
		if (ray->raydir.x > 0)
			texture->used_tex = texture->west_text;
		else
			texture->used_tex = texture->east_text;
	}
}

void	coordinate_on_textures(t_raycast_data *ray, t_textures *texture)
{
	texture->texx = (int)(texture->wallx * (double)texture->used_tex->width); // this has to be the texture you are using right now
	if (ray->side_hit == HORIZONTAL && ray->raydir.x > 0)
		texture->texx = texture->used_tex->width - texture->texx - 1;
	if (ray->side_hit == VERTICAL && ray->raydir.y < 0)
		texture->texx = texture->used_tex->width - texture->texx - 1;
}

void	raycaster(void *param)
{
	t_raycast_data	*raycast; // remove
	t_player		*player;
	t_textures		*texture;
	t_vector	raydir;
	t_vector	delta_dist;

	raycast = (t_raycast_data *)param; //rm
	player = &raycast->data->player;
	texture = &raycast->data->textures;
	int	x;
	double cameraX;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * (x / (double)WIDTH) - 1;
		raycast->mapX = player->pos.x;
		raycast->mapY = player->pos.y;
		printf("do I get here?\n");
		raycast->raydir.x = player->dir.x + player->plane.x * cameraX;
		raycast->raydir.y = player->dir.y + player->plane.y * cameraX;
		raycast->delta_dist = calc_delta_dist(raycast->raydir);
		calc_side_dist(raycast, player);
		keep_lookin(raycast);
		if (raycast->side_hit == HORIZONTAL)
		{
			raycast->perp_dist = (raycast->side_distX - raycast->delta_dist.x);
			texture->wallx = (raycast->raydir.y * raycast->perp_dist) + player->pos.y; //calculate value of wallx
		}
		else
		{	
			raycast->perp_dist = (raycast->side_distY - raycast->delta_dist.y);
			texture->wallx = (raycast->raydir.x * raycast->perp_dist) + player->pos.x; //calculate value of wallx
		}
		texture->wallx -= floor(texture->wallx);
		get_side_texture(raycast, texture);
		coordinate_on_textures(raycast, texture);
		draw_line(raycast, x, texture);
		x++;
	}
}

void	keep_lookin(t_raycast_data *raycast)
{
	while (1)
	{
		if (raycast->side_distX < raycast->side_distY)
		{
			raycast->side_distX += raycast->delta_dist.x;
			raycast->mapX += raycast->stepX;
			raycast->side_hit = HORIZONTAL;
		}
		else
		{
			raycast->side_distY += raycast->delta_dist.y;
			raycast->mapY += raycast->stepY;
			raycast->side_hit = VERTICAL;
		}
		if (raycast->map->content[raycast->mapY][raycast->mapX] == '1') //removed out of bounds check
			break;
	}
}

static t_vector	calc_delta_dist(t_vector raydir) //take raydir, return delta dist
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


//calculates the side_distance, which is the distnace from the starting pos
// to the nearest gridline, as well as checking if we need the step adjustment
static void	calc_side_dist(t_raycast_data *raycast, t_player *player) //take raydir
{
	if (raycast->raydir.x < 0)
	{
		raycast->stepX = NEGATIVE;
		raycast->side_distX = (player->pos.x - raycast->mapX) * raycast->delta_dist.x;
	}
	else
	{
		raycast->stepX = POSITIVE;
		raycast->side_distX =(raycast->mapX+ 1.0 - player->pos.x) * raycast->delta_dist.x;
	}
	if (raycast->raydir.y < 0)
	{
		raycast->stepY = NEGATIVE;
		raycast->side_distY =(player->pos.y - raycast->mapY) * raycast->delta_dist.y;
	}
	else
	{
		raycast->stepY = POSITIVE;
		raycast->side_distY =(raycast->mapY + 1.0 -  player->pos.y) * raycast->delta_dist.y;
	}
}

void	draw_line(t_raycast_data *raycast, int x, t_textures *texture) //take perpdist and wall object
{
	long	draw_start;
	long	draw_end;
	int	lineheight = (int)HEIGHT / raycast->perp_dist;
	uint32_t colour;
	draw_start = -lineheight / 2 + HEIGHT / 2;
	if(draw_start < 0)
		draw_start = 0;
	draw_end = lineheight / 2 + HEIGHT / 2;

	raycast->step = 1.0 * texture->used_tex->height / lineheight;
	texture->tex_pos = (draw_start - HEIGHT / 2 + lineheight / 2) * raycast->step;
	if(draw_end >= HEIGHT)
	  	draw_end = HEIGHT - 1;
	while (draw_start < draw_end)
	{
		texture->texture_y = (int)texture->tex_pos & (texture->used_tex->height - 1);
		texture->tex_pos += raycast->step;
		colour = texture_colours(texture, x, draw_start, 0);
		mlx_put_pixel(raycast->data->wall, x, draw_start, colour);
		draw_start++;
	}
}
