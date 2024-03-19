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
