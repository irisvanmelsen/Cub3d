/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iris <iris@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 18:06:51 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/04/12 22:15:15 by iris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
	texture->texx = (int)(texture->wallx * (double)texture->used_tex->width);
	if (ray->side_hit == HORIZONTAL && ray->raydir.x > 0)
		texture->texx = texture->used_tex->width - texture->texx - 1;
	if (ray->side_hit == VERTICAL && ray->raydir.y < 0)
		texture->texx = texture->used_tex->width - texture->texx - 1;
}

void	raycaster(void *param)
{
	t_raycast_data	*raycast;
	t_player		*player;
	t_textures		*texture;

	raycast = (t_raycast_data *)param;
	player = &raycast->data->player;
	texture = &raycast->data->textures;
	int	x;
	double cameraX;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * (x / (double)WIDTH) - 1;
		raycast->mapX = (int)player->pos.x;
		raycast->mapY = (int)player->pos.y;
		raycast->raydir.x = player->dir.x + player->plane.x * cameraX;
		raycast->raydir.y = player->dir.y + player->plane.y * cameraX;
		raycast->delta_dist = calc_delta_dist(raycast->raydir);
		// raycast->side_dist.x = calc_side_dist_new(raycast->raydir.x,\
		// 				 player->pos.x, raycast->mapX, raycast->delta_dist.x);
		// raycast->side_dist.y = calc_side_dist_new(raycast->raydir.y,\
		// 				 player->pos.y, raycast->mapY, raycast->delta_dist.y);
		calc_side_dist(raycast, player);
		keep_lookin(raycast);
		texture->wallx = calc_perp_dist_and_wallX(raycast, player);
		get_side_texture(raycast, texture);
		coordinate_on_textures(raycast, texture); //can be merged w get side tex?
		draw_line(raycast, x, texture);
		x++;
	}
}

void	keep_lookin(t_raycast_data *raycast)
{
	while (1)
	{
		if (raycast->side_dist.x < raycast->side_dist.y)
		{
			raycast->side_distX += raycast->delta_dist.x;
			raycast->mapX += raycast->map_stepdir_X; //rename step to mapdir?
			raycast->side_hit = HORIZONTAL;
		}
		else
		{
			raycast->side_distY += raycast->delta_dist.y;
			raycast->mapY += raycast->map_stepdir_Y;
			raycast->side_hit = VERTICAL;
		}
		if (raycast->data->map->content[raycast->mapY][raycast->mapX] == '1')
			break;
	}
}

void	draw_line(t_raycast_data *raycast, int x, t_textures *texture) //take perpdist and wall object
{
	long	draw_start;
	long	draw_end;
	int	lineheight;
	uint32_t colour;

	lineheight = (int)HEIGHT / raycast->perp_dist;
	draw_start = -lineheight / 2 + HALF_HEIGHT;
	draw_end = lineheight / 2 + HALF_HEIGHT;
	if(draw_start < 0)
		draw_start = 0;
	if(draw_end >= HEIGHT)
	  	draw_end = HEIGHT - 1;
	raycast->step = (1.0 * texture->used_tex->height / lineheight);
	texture->tex_pos = (draw_start - (HALF_HEIGHT) + (lineheight / 2)) * raycast->step;
	while (draw_start < draw_end && draw_start < HEIGHT)
	{
		texture->texture_y = (int)texture->tex_pos & (texture->used_tex->height - 1); //?
		texture->tex_pos += raycast->step;
		colour = texture_colours(texture, texture->texx, texture->texture_y, 0);
		mlx_put_pixel(raycast->data->wall, x, draw_start, colour);
		draw_start++;
	}
}
