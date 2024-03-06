/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:04:45 by ivan-mel      #+#    #+#                 */
/*   Updated: 2024/02/12 16:51:00 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	mlx_window_setup(t_cub3d *cub3d)
{
 	if (mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	if (mlx_image_to_window(cub3d->mlx, cub3d->wall, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	// if (mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0) == -1)
	// 	print_error(get_error_name(ERROR_IMAGE));
}

int	mlx_image_setup(t_cub3d *cub3d)
{
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		return (print_error(get_error_name(ERROR_IMAGE)));
	cub3d->wall = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->wall)
		return (print_error(get_error_name(ERROR_IMAGE)));
	// cub3d->minimap = mlx_new_image(cub3d->mlx, cub3d->mlx->width * TILE, \
	// 	cub3d->mlx->height * TILE);
	// if (!cub3d->minimap)
	// 	return (print_error(get_error_name(ERROR_IMAGE)));
	mlx_window_setup(cub3d);
	return (1);
}


void init_nbrs(t_nbrs *nbrs, t_cub3d *data)
{
	ft_bzero((void *)nbrs, sizeof(*nbrs));
	nbrs->data = data;
	nbrs->map = data->map;
	nbrs->mapX = nbrs->map->player_x;
	nbrs->mapY = nbrs->map->player_y;
	set_initial_look_dirs(data, nbrs);
}


void	mlx_setup(t_cub3d *cub3d)
{
	t_nbrs nbrs;

	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX)); //clean exit?
	mlx_image_setup(cub3d);
	background_setup(cub3d->background);
	init_nbrs(&nbrs, cub3d);
	raycast(&nbrs);
	// mlx_loop_hook(cub3d->mlx, raycast ,(void *)&nbrs);
	mlx_cursor_hook(cub3d->mlx, (mlx_cursorfunc)mouse_move, (void *)cub3d);
	mlx_loop(cub3d->mlx);
	mlx_terminate(cub3d->mlx);
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
