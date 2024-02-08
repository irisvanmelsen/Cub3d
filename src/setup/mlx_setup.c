/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:04:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/02/08 15:44:24 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mlx_window_setup(t_cub3d *cub3d)
{
	if (!mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0) || \
		!mlx_image_to_window(cub3d->mlx, cub3d->wall, 0, 0) || \
		!mlx_image_to_window(cub3d->mlx, cub3d->minimap, 0, 0))
		print_error(get_error_name(ERROR_IMAGE));

}

void	mlx_image_setup(t_cub3d *cub3d)
{
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d->wall = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->wall)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d->minimap = mlx_new_image(cub3d->mlx, cub3d->mlx->width * TILE, \
		cub3d->mlx->height * TILE);
	if (!cub3d->minimap)
		print_error(get_error_name(ERROR_IMAGE));
}

void	mlx_setup(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX));
	printf("hallo?\n");
	mlx_image_setup(cub3d);
	player_setup(cub3d);
	// cub3d->colour.floor = pixel_setup();
	// background_setup(cub3d);
}
