/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/01 18:06:51 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/05/09 16:27:53 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_side_texture(t_raycast_data *ray, t_textures *texture)
{
	if (ray->side_hit == VERTICAL)
	{
		if (ray->raydir.y > 0)
			texture->used_tex = texture->north;
		else
			texture->used_tex = texture->south;
	}
	else if (ray->side_hit == HORIZONTAL)
	{
		if (ray->raydir.x > 0)
			texture->used_tex = texture->west;
		else
			texture->used_tex = texture->east;
	}
}

void	init_raycaster(t_raycast_data *raycast, t_player *player, \
double camerax)
{
	raycast->maptile.x = (int)player->pos.x;
	raycast->maptile.y = (int)player->pos.y;
	raycast->raydir.x = player->dir.x + player->plane.x * camerax;
	raycast->raydir.y = player->dir.y + player->plane.y * camerax;
}

void	raycaster(void *param)
{
	t_raycast_data	*raycast;
	t_player		*player;
	t_textures		*texture;
	int				x;
	double			camerax;

	raycast = (t_raycast_data *)param;
	player = &raycast->data->player;
	texture = &raycast->data->textures;
	x = 0;
	while (x < WIDTH)
	{
		camerax = 2 * (x / (double)WIDTH) - 1;
		init_raycaster(raycast, player, camerax);
		raycast->delta_dist = calc_delta_dist(raycast->raydir);
		calc_side_dist(raycast, player);
		keep_lookin(raycast);
		texture->wallx = calc_perp_dist_and_wallx(raycast, player);
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
		if (raycast->side_dist.x < raycast->side_dist.y)
		{
			raycast->side_dist.x += raycast->delta_dist.x;
			raycast->maptile.x += raycast->map_stepdir.x;
			raycast->side_hit = HORIZONTAL;
		}
		else
		{
			raycast->side_dist.y += raycast->delta_dist.y;
			raycast->maptile.y += raycast->map_stepdir.y;
			raycast->side_hit = VERTICAL;
		}
		if (raycast->data->map->content[raycast->maptile.y] \
			[raycast->maptile.x] == '1')
			break ;
	}
}

void	draw_line(t_raycast_data *raycast, int x, t_textures *texture)
{
	long		draw_start;
	long		draw_end;
	int			lineheight;
	uint32_t	colour;

	lineheight = (int)HEIGHT / raycast->perp_dist;
	draw_start = -lineheight / 2 + HALF_HEIGHT;
	draw_end = lineheight / 2 + HALF_HEIGHT;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	raycast->step = (1.0 * texture->used_tex->height / lineheight);
	texture->tex_pos = (draw_start - (HALF_HEIGHT) + (lineheight / 2)) * \
	raycast->step;
	while (draw_start < draw_end && draw_start < HEIGHT)
	{
		texture->texture_y = (int)texture->tex_pos & \
		(texture->used_tex->height - 1);
		texture->tex_pos += raycast->step;
		colour = texture_colours(texture, texture->texx, texture->texture_y);
		mlx_put_pixel(raycast->data->wall, x, draw_start, colour);
		draw_start++;
	}
}
