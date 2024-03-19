/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cubed.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivan-mel <ivan-mel@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/08 15:20:50 by ivan-mel      #+#    #+#                 */
/*   Updated: 2024/02/08 15:32:56 by ivan-mel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cubed(int argc, char **argv)
{
	t_cub3d	cub3d;
	t_map	map;
	t_raycast_data raycast;

	if (!parsing(argc, argv, &cub3d, &map))
		return (print_error("PARSING ERROR\n"));
	init_cub3d_data(&cub3d, &map, &raycast);
	mlx_setup(&cub3d);
	return (1);
}

void	mlx_setup(t_cub3d *cub3d)
{

	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX)); //clean exit?
	mlx_image_setup(cub3d);
	background_setup(cub3d->background);
	init_raycast_data(cub3d->raycast, cub3d);
	raycaster(cub3d->raycast);
	mlx_loop_hook(cub3d->mlx, cub3d_loop ,(void *)cub3d);
	mlx_loop(cub3d->mlx);
	// mlx_set_mouse_pos(game->mlx, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	// mlx_cursor_hook(cub3d->mlx, (mlx_cursorfunc)mouse_move, (void *)cub3d);
	// mlx_key_hook(cub3d->mlx, (mlx_keyfunc)cub3d_loop, (void *)cub3d);
	mlx_terminate(cub3d->mlx);
}
