/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:04:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/02/02 16:52:23 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mlx_window_setup(t_cub3d *cub3d)
{
	mlx_image_to_window();
	mlx_image_to_window();
	mlx_image_to_window();
	
}

void	mlx_setup(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX));
	cub3d->image = mlx_new_image(cub3d->mlx,
		cub3d->mlx->width, cub3d->mlx->height);
	if (!cub3d->image)
		print_error(get_error_name(ERROR_IMAGE));
}
