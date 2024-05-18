/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iris <iris@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:04:45 by ivan-mel          #+#    #+#             */
/*   Updated: 2024/05/18 18:52:43 by iris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	game_setup(t_cub3d *cub3d)
{
	mlx_image_setup(cub3d);
	init_raycast_data(cub3d->raycast, cub3d);
	raycaster(cub3d->raycast);
	start_minimap(cub3d);
	mlx_set_cursor_mode(cub3d->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(cub3d->mlx, main_game_loop, (void *)cub3d);
	mlx_loop(cub3d->mlx);
}

int	mlx_image_setup(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!cub3d->mlx)
		print_error(get_error_name(ERROR_MLX));
	cub3d->background = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->background)
		return (print_error(get_error_name(ERROR_IMAGE)));
	cub3d->wall = mlx_new_image(cub3d->mlx, WIDTH, HEIGHT);
	if (!cub3d->wall)
		return (print_error(get_error_name(ERROR_IMAGE)));
	if (mlx_image_to_window(cub3d->mlx, cub3d->background, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	if (mlx_image_to_window(cub3d->mlx, cub3d->wall, 0, 0) == -1)
		print_error(get_error_name(ERROR_IMAGE));
	cub3d_memset(cub3d->background->pixels, 0xD5A6BD00, HALF_SCREENSIZE);
	cub3d_memset(&cub3d->background->pixels[HALF_SCREENSIZE * 4], \
	0x8E7CC300, HALF_SCREENSIZE);
	return (1);
}

void	cub3d_memset(void *b, int colour, size_t len)
{
	size_t	i;
	int		*img;

	img = b;
	i = 0;
	while (i < len)
	{
		img[i] = colour;
		i++;
	}
}
