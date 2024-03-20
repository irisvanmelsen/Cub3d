/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:04:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/03/20 08:44:56 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	delta_dist(t_nbrs *nbrs);


void	mlx_window_setup(t_cub3d *cub3d)
{
 	if (mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	if (mlx_image_to_window(cub3d->mlx, cub3d->wall, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
}

int	mlx_image_setup(t_cub3d *cub3d)
{
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		return (print_error(get_error_name(ERROR_IMAGE)));
	cub3d->wall = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->wall)
		return (print_error(get_error_name(ERROR_IMAGE)));
	mlx_window_setup(cub3d);
	return (1);
}

// void	cub3d_loop(void	*param)
// {
// 	t_cub3d *m;

// 	m = param;

// 	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(m->mlx);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_W))
// 		take_step_y(&m->player, m->map, -1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_UP))
// 		take_step_y(&m->player, m->map, -1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_S))
// 		take_step_y(&m->player, m->map, 1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_DOWN))
// 		take_step_y(&m->player, m->map, 1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_D))
// 		take_step_x(&m->player, m->map, -1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_RIGHT))
// 		take_step_x(&m->player, m->map, -1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_A))
// 		take_step_x(&m->player, m->map, 1, m->mlx->delta_time);
// 	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT))
// 		take_step_x(&m->player, m->map, 1, m->mlx->delta_time);
// }

void init_nbrs(t_nbrs *nbrs, t_cub3d *data)
{
	ft_bzero((void *)nbrs, sizeof(*nbrs));
	nbrs->data = data;
	nbrs->map = data->map;
	nbrs->mapX = nbrs->map->player_x;
	nbrs->mapY = nbrs->map->player_y;
}


void	mlx_setup(t_cub3d *cub3d)
{
	t_nbrs nbrs;

	printf("segfault ik hier?\n");
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX)); //clean exit?
	mlx_image_setup(cub3d);
	background_setup(cub3d->background);
	player_setup(cub3d);
	init_nbrs(&nbrs, cub3d);
	raycast(&nbrs);
	start_minimap(cub3d);
	// mlx_loop_hook(cub3d->mlx, raycast(&nbrs, cub3d->map),cub3d);
	mlx_loop(cub3d->mlx);
	mlx_close_window(cub3d->mlx);
}


// void	*raycast(t_nbrs *nbrs, t_map *map)
// {
// 	calculate_raydirs(nbrs);
// 	return (NULL);
// }

void	raycast(t_nbrs *nbrs)
{

	int	x;
	double cameraX;
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //this would be for facing WEST
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / (double)WIDTH - (float)1; //x-coordinate in camera space
		nbrs->mapX = nbrs->map->player_x;
		nbrs->mapY = nbrs->map->player_y;
		nbrs->rayDirX = dirX + planeX * cameraX;
		nbrs->rayDirY = dirY + planeY * cameraX;
		delta_dist(nbrs);
		calc_side_dist(nbrs);
		keep_lookin(nbrs);
		if (nbrs->side_hit == HORIZONTAL)
			nbrs->perp_dist = (nbrs->side_distX - nbrs->delta_distX);
		else
			nbrs->perp_dist = (nbrs->side_distY - nbrs->delta_distY);
		draw_line(nbrs, x);
		x++;
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

void	keep_lookin(t_nbrs *nbrs)
{
	// nbrs->eucli_distX += nbrs->side_distX;
	// nbrs->eucli_distY += nbrs->side_distY;
	int x = 0;
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
		if (nbrs->mapY < 0 || nbrs->mapX < 0 || nbrs->map->content[nbrs->mapY][nbrs->mapX] == '1')
		{
			// printf("\n----RAYCAST HIT----%i\n\n", x);
			break;
		}
		mlx_put_pixel(nbrs->data->wall, nbrs->mapX, nbrs->mapY, get_rgba(0, 255, 150, 255));
		x++;
	}
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
	// printf("PERPDIST = %f on x%i,\n", nbrs->perp_dist, x);
	while (draw_start < draw_end)
	{
		mlx_put_pixel(nbrs->data->wall, x, draw_start, get_rgba(0, 255, 0, 255));
		draw_start++;
	}

}

	// t_vector Hitpoint = {nbrs->mapX + (1 - nbrs->stepX) / 2, \
	// 			nbrs->mapY + (1 - nbrs->stepY) / 2};

// void	calc_perp_distance(t_nbrs *nbrs)
// {
// 	if (nbrs->side_hit == HORIZONTAL)
// 		nbrs->perp_dist = (nbrs->eucli_distX - nbrs->delta_distX);
// 	else
// 		nbrs->perp_dist = (nbrs->eucli_distY - nbrs->delta_distY);

// }

// void	fuck_around(void)
// {


// 	double posX = 22, posY = 12;
// 	double dirX = -1, dirY = 0; //initial direction vector

// 	double time = 0; //time of current frame
// 	double oldTime = 0; //time of previous frame


// }



//plane gaat van -1 naar 1

// double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
// double rayDirX = dirX + planeX * cameraX;
// double rayDirY = dirY + planeY * cameraX;

//direction vector is black line from player to plane (aka screen)
// bepalen we dat zelf?



//direction en plane zijn HARDCODED?
// ^ if same FOV == 90


//raycast = dir + plane * 0.33


//CAMERA X IS HET ZWARTE PUNTJE MIDDEN VAN PLANE
